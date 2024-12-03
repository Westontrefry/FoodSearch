#ifndef FOODGRAPH_H
#define FOODGRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "Food.h"

class GraphNode {
public:
    Food* food;
    std::vector<std::pair<GraphNode*, std::string>> edges;

     GraphNode(Food* foodItem) : food(foodItem) {}

    void addEdge(GraphNode* targetNode, const std::string& attribute)
    {
        for (const auto& edge : edges)
        {
            if (edge.first == targetNode && edge.second == attribute)
            {
                return;
            }
        }

        edges.push_back(std::make_pair(targetNode, attribute));
    }
};

class FoodGraph {
private:
    std::vector<GraphNode*> vertices;

    void outputCSV(const std::vector<const Food*>& foundFoods) const
    {
        std::ofstream outputFile("GraphOutputData.csv");

        if (!outputFile.is_open())
        {
            std::cerr << "Failed to open the file for writing." << std::endl;
            return;
        }

        std::stringstream ss;
        ss << "Food Description,Fiber,Protein,Sodium,Sugars,Saturated Fat,Energy\n";

        for (const Food* food : foundFoods)
        {
            ss << "\"" << food->getDescription() << "\","
               << food->getFiber() << ","
               << food->getProtein() << ","
               << food->getSodium() << ","
               << food->getSugars() << ","
               << food->getSatFats() << ","
               << food->getEnergy() << "\n";
        }

        outputFile << ss.str();
        outputFile.close();

        std::cout << "CSV file has been successfully written." << std::endl;
    }

    std::string toLowerCase(const std::string& str) const
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    void addEdgeBasedOnAttribute(GraphNode* node1, GraphNode* node2, const std::string& attribute)
    {
        node1->addEdge(node2, attribute);
        node2->addEdge(node1, attribute); 
    }

public:

    FoodGraph() {}

    void addFood(Food* foodItem)
    {
        GraphNode* newNode = new GraphNode(foodItem);
        vertices.push_back(newNode);
        std::unordered_map<float, std::vector<GraphNode*>> fiberMap;
        std::unordered_map<float, std::vector<GraphNode*>> proteinMap;
        std::unordered_map<float, std::vector<GraphNode*>> sodiumMap;
        std::unordered_map<float, std::vector<GraphNode*>> sugarMap;
        std::unordered_map<float, std::vector<GraphNode*>> fatMap;
        std::unordered_map<float, std::vector<GraphNode*>> energyMap;
        fiberMap[foodItem->getFiber()].push_back(newNode);
        proteinMap[foodItem->getProtein()].push_back(newNode);
        sodiumMap[foodItem->getSodium()].push_back(newNode);
        sugarMap[foodItem->getSugars()].push_back(newNode);
        fatMap[foodItem->getSatFats()].push_back(newNode);
        energyMap[foodItem->getEnergy()].push_back(newNode);

        for (auto& pair : fiberMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Fiber");
                }
            }
        }

        for (auto& pair : proteinMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Protein");
                }
            }
        }

        for (auto& pair : sodiumMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Sodium");
                }
            }
        }

        for (auto& pair : sugarMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Sugar");
                }
            }
        }

        for (auto& pair : fatMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Saturated_Fat");
                }
            }
        }

        for (auto& pair : energyMap)
        {
            for (GraphNode* existingNode : pair.second)
            {
                if (existingNode != newNode)
                {
                    addEdgeBasedOnAttribute(existingNode, newNode, "Energy");
                }
            }
        }
    }

    void search_by_description_bfs(const std::string& descriptionSubstring) const
    {
        std::vector<const Food*> foundFoods;
        std::queue<GraphNode*> queue;
        std::unordered_set<GraphNode*> visited;
        std::string lowerDescriptionSubstring = toLowerCase(descriptionSubstring);

        for (GraphNode* node : vertices)
        {
            if (visited.find(node) == visited.end())
            {
                queue.push(node);
                visited.insert(node);
            }
        }

        while (!queue.empty())
        {
            GraphNode* currentNode = queue.front();
            queue.pop();
            std::string foodDescription = toLowerCase(currentNode->food->getDescription());

            if (foodDescription.find(lowerDescriptionSubstring) != std::string::npos)
            {
                foundFoods.push_back(currentNode->food);
            }

            for (const auto& edge : currentNode->edges)
            {
                if (visited.find(edge.first) == visited.end())
                {
                    queue.push(edge.first);
                    visited.insert(edge.first);
                }
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_name(const std::string& searchFoodName) const
    {
        std::vector<const Food*> foundFoods;
        std::string lowerSearchName = toLowerCase(searchFoodName);

        for (const GraphNode* node : vertices)
        {
            std::string foodName = toLowerCase(node->food->getDescription());
            if (foodName.find(lowerSearchName) != std::string::npos)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_fiber(float fiber) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getFiber() == fiber)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_protein(float protein) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getProtein() == protein)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_sodium(float sodium) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getSodium() == sodium)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_sugars(float sugars) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getSugars() == sugars)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_saturated_fat(float saturatedFat) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getSatFats() == saturatedFat)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }

    void search_by_energy(float energy) const
    {
        std::vector<const Food*> foundFoods;

        for (const GraphNode* node : vertices)
        {
            if (node->food->getEnergy() == energy)
            {
                foundFoods.push_back(node->food);
            }
        }

        outputCSV(foundFoods);
    }
};

#endif // FOODGRAPH_H
