//
// Created by Weston Trefry on 11/30/24.
//
#include <iostream>
#include <string>
#include <sstream>
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
    foods = food.readFile("../data/FoodData.csv");
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
        cin >> userInput;                                       // added ShanonB

        if (userInput == 2) {
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
            std::cout << "1. Food Description Keyword\n"
                         "2. Fiber\n3. Protein \n4. Sodium \n"
                         "5. Sugars \n6. Saturated Fats \n7. Exit Program\n";
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


            if (tableType == 1) {
                std::cout << "You have chosen the HashTable." << std::endl;
                std::string foodName;
                std::cout << "Search by food description:   ";
                std::vector<Food> matches;

            switch (filterChoice) {
                    // Vector for storing all matches

                    case (1): {
                    /*=== Exact Match Search: if there is an exact match, O(1) complexity ===*/
                    auto match = foodHashTable.getFood(foodName);
                    if (match.has_value()) {
                        // Key found,
                        matches.push_back(match.value());
                        std::cout << "Food item found in Hash Table!" << endl;
                    }
                    /*=== Partial Match Search: O(n) due to searching all keys ===*/
                    else {
                        // Search all keys (descriptions) to look for partial
                        // Make user input lower case with tolower() function
                        std::string lowerCase; // converted string
                        for (char i : foodName) {
                            lowerCase += static_cast<char>(tolower(i));
                        }
                        // Iterate through foods vector to look for partial matches
                        for(Food* food : foods) {
                            std::string description;
                            for (char i : food->getDescription()) {
                                description += static_cast<char>(tolower(i));
                            }

                            // Search Hash Table, if match found somewhere in description, push onto vector
                            if (description.find(lowerCase) != std::string::npos) {
                                // Get the food item from table, then check if it has a value & add to vector
                                auto hashFood = foodHashTable.getFood(food->getDescription());
                                // Check that match (key) has value pair and push back to matches vector
                                if (hashFood) {
                                    matches.push_back(hashFood.value());
                                }
                            }
                        }
                        std::cout << "A total of " << matches.size() << " matches have been found." << endl;
                    }
                    if (matches.size() == 1) {
                        std::cout << "An exact match has been found!" << endl;
                    }
                }
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
