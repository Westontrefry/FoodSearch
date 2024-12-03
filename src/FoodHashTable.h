#ifndef FOODHASHTABLE_H
#define FOODHASHTABLE_H

#include <string>
#include <vector>
#include <utility>
#include <optional>
#include <iostream>
#include "Food.h"

using namespace std;

class FoodHashTable {
    int size;
    int numFood;
    vector<vector<pair<string, Food>>> table;
public:
    FoodHashTable(int size);
    int hashFunction(string key);
    void insert(string key, Food food);
    void remove(string key);
    optional<Food> getFood(string key);
    vector<const Food*> filter(string filterValue);
    vector<const Food*> searchByFiber(float fiberCount);
    vector<const Food*> searchByProtein(float proteinCount);
    vector<const Food*> searchBySodium(float sodiumCount);
    vector<const Food*> searchBySugars(float sugarCount);
    vector<const Food*> searchBySatFats(float satFatCount);
    vector<const Food*> searchByEnergy(float energyCount);
};

#endif
