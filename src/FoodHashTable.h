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
};

#endif
