
#ifndef FOODGRAPH_H
#define FOODGRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include "Food.h"

class Graph
{
public:
    void insert_food(const Food &food)
    {
        name_graph[food.getDescription()].push_back(food);
    }

    void search_by_name(const std::string &food_name) const
    {
        auto it = name_graph.find(food_name);
        if (it != name_graph.end())
        {
            std::cout << "Found " << it->second.size() << " food items with name: " << food_name << "\n";
            for (const auto &food : it->second) {
                std::cout << "Food Item: " << food.getDescription() << "\n";
            }
        }
        else
        {
            std::cout << "No food items found with name: " << food_name << "\n";
        }
    }

private:
    std::unordered_map<std::string, std::vector<Food>> name_graph;
};

#endif // FOODGRAPH_H