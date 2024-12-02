#include "FoodHashTable.h"

FoodHashTable::FoodHashTable(int size) :
    size(size),
    numFood(0),
    table(size) {}

int FoodHashTable::hashFunction(string key) {
    int hash = 0;
    for (char c : key) {
        int ascii = c;
        hash = hash * 31 + ascii;
    }

    return (hash % size + size) % size;
}

void FoodHashTable::insert(string key, Food food) {
    int hash = hashFunction(key);
    for (auto& pair : table[hash]) {
        if (key == pair.first) {
            pair.second = food;
            return;
        }
    }

    table[hash].emplace_back(key, food);
    numFood++;

    // Handle resizing if load factor > 0.75
    if (static_cast<float>(numFood) / size > 0.75) {
        vector<vector<pair<string, Food>>> newTable(size * 2);

        for (auto& bucket : table) {
            for (auto& pair : bucket) {
                int newIndex = hashFunction(pair.first) % (size * 2);
                newTable[newIndex].emplace_back(pair.first, pair.second);
            }
        }

        table = newTable;
        size = size * 2;
    }
}

void FoodHashTable::remove(string key) {
    int hash = hashFunction(key);
    for (auto it = table[hash].begin(); it != table[hash].end(); it++) {
        if (key == it->first) {
            table[hash].erase(it);
            numFood--;
            return;
        }
    }

    cout << "Key not found" << endl;
}

optional<Food> FoodHashTable::getFood(string key) {
    int hash = hashFunction(key);
    for (auto& pair : table[hash]) {
        if (key == pair.first) {
            return pair.second;
        }
    }

    return nullopt;
}

