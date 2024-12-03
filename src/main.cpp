//
// Created by Weston Trefry on 11/30/24.
//
#include <iostream>
#include <string>
#include "Food.h"
#include "FoodGraph.h" //add header file - ShanonB
#include "FoodHashTable.h"

int main() {
    /*=== Instantiate Data Structure Objects ===*/
    // Create Table Object
    // HashTable foodTable;
    FoodGraph foodGraph; // Create Graph Object - added ShanonB

    FoodHashTable foodHashTable(10);

    /*=== Load Data from FoodData.csv ===*/
    // Create Food class object
    Food food;
    // Read file using Food::readFile function and pushback onto vector
    std::vector<Food*> foods;
    foods = food.readFile("FoodData.csv");
    // Iterate over vector and build both data structures item by item
    for (Food* food : foods) {
        foodGraph.addFood(food); //insert food data into graph added ShanonB

        foodHashTable.insert(food->getDescription(), *food); // Function takes in description of the food item in csv and then the food item
    }

    /*=== Main logic loop ===*/
    while (true) {
        // Prompt user for input (search a food item)
        std::cout << "Select 1 to search for a food item." << std::endl;
        std::cout << "Select 2 to exit the program." << std::endl;
        int userInput;                                                    //changed to int - ShanonB
        std::cin >> userInput;                                            // added ShanonB

        if (userInput == "2") {
            break;
        }
      //  if (userInput == "1") {
            // Prompt user to select a filter (menu of nutrient types)
     ///       std::cout << "Filter by nutrient: " << std::endl;
      //      std::cout << "1. Fiber\n 2. Protein \n 3. Sodium \n "
      //                   "4. Sugars \n 5. Saturated Fats \n";
      //  }

        if (userInput == 1) {
            // Prompt user to select a filter (menu of nutrient types)    -- modified ShanonB
            std::cout << "Search for food name or by food description keyword or filter by nutrient: " << std::endl;
            std::cout << "1. Food Name\n2. Food Description Keyword\n"
                         "3. Fiber\n4. Protein \n5. Sodium \n"
                         "6. Sugars \n7. Saturated Fats \n8. Exit Program\n";
            int filterChoice;
            std::cout << "Enter the nutrient number: ";
            std::cin >> filterChoice;                           //added ShanonB
            
            if (filterChoice == 8)
            {
                break;
            }

            int tableType;
            std::cout << "Select the Type of Data Structure to use.\n";
            std::cout << "  Select 1 to use the HashTable.\n";
            std::cout << "  Select 2 to use the Graph.\n";
            std::cout << "  Select 3 to exit the program.\n";
            std::cin >> tableType;


            if (tableType == 1)
            {
                std::cout << "You have chosen the HashTable." << std::endl;
                switch (filterChoice)
                {
                case 1:
                    // add hash function
                        continue;
                case 2:
                    // add hash function
                        continue;
                case 3:
                    // add hash function
                        continue;
                case 4:
                    // add hash function
                        continue;
                case 5:
                    // add hash function
                        continue;
                }
            }
            else if (tableType == 2)
            {
                std::cout << "You have chosen the Graph." << std::endl;
                switch (filterChoice)
                {
                case 1:
                    {
                        std::string foodName;
                        std::cout << "Search by food name, enter the name:   ";
                        std::cin >> foodName;
                        foodGraph.search_by_name(foodName);
                        continue;
                    }
                case 2:
                    {
                        std::string keyword;
                        std::cout << "Search by food description keyword (ex. cracker), enter the keyword:   ";
                        std::cin >> keyword;
                        foodGraph.search_by_description_bfs(keyword);
                        continue;
                    }
                case 3:
                    {
                        float fiberAmount;
                        std::cout << "Enter the amount of fiber to search for:   ";
                        std::cin >> fiberAmount;
                        foodGraph.search_by_fiber(fiberAmount);
                        continue;
                    }
                case 4:
                    {
                        float proteinAmount;
                        std::cout << "Enter the amount of protein to search for:   ";
                        std::cin >> proteinAmount;
                        foodGraph.search_by_protein(proteinAmount);
                        continue;
                    }
                case 5:
                    {
                        float sodiumAmount;
                        std::cout << "Enter the amount of sodium to search for:    ";
                        std::cin >> sodiumAmount;
                        foodGraph.search_by_sodium(sodiumAmount);
                        continue;
                    }
                case 6:
                    {
                        float sugarsAmount;
                        std::cout << "Enter the amount of sugars to search for:    ";
                        std::cin >> sugarsAmount;
                        foodGraph.search_by_sugars(sugarsAmount);
                        continue;
                    }
                case 7:
                    {
                        float fatsAmount;
                        std::cout << "Enter the amount of saturated fats to search for:    ";
                        std::cin >> fatsAmount;
                        foodGraph.search_by_saturated_fat(fatsAmount);
                        continue;
                    }

                }
            }
            else if (tableType == 3)
            {
                break;
            }
        }

        // Give user option to exit the program (exit while loop)

        /*=== Building Data Structures + Search ===*/
        // Ask user what data structure to build: 1. HashTable, 2. Graph
        // If hash table
        // Get items using hashtable search function
        // Push back onto vector
        // If graph
        // Get items using graph search function
        // Push back onto vector

        /*=== Displaying Search Results ===*/
        // Display vector items to console
        // Write items to a CSV (in a pair)
    }
        


    return 0;
}
