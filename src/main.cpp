//
// Created by Weston Trefry on 11/30/24.
//
#include <iostream>
#include "Food.h"
#include "FoodGraph.h" //add header file - ShanonB
#include "FoodHashTable.h"

void displayMenu() {
    std::cout << "======== Welcome to FoodSearch ========\n";
    std::cout << "1. Search food items by entering a description";
    std::cout << "2. Exit the program\n";
    std::cout << "Make a selection by typing 1 or 2\n";
}

void displayNutrientMenu() {
    std::cout << "Filter by nutrient:\n";
    std::cout << "1. Fiber\n";
    std::cout << "2. Protein\n";
    std::cout << "3. Sodium\n";
    std::cout << "4. Sugars\n";
    std::cout << "5. Saturated Fats\n";
    std::cout << "Make a selection by typing 1 through 5\n";
}

int main() {
    /*=== Instantiate Data Structure Objects ===*/
    // Create Table Object
    FoodGraph foodGraph; // Create Graph Object - added ShanonB

    FoodHashTable foodHashTable(10);

    /*=== Load Data from FoodData.csv ===*/
    // Create Food class object
    Food food;
    // Read file using Food::readFile function and pushback onto vector
    std::vector<Food*> foods;
    foods = food.readFile("../data/FoodData.csv");
    std::cout << "Size of Food object vector after reading file: " << foods.size() << std::endl;
    // Iterate over vector and build both data structures item by item
    for (Food* food : foods) {
        foodGraph.addFood(food); //insert food data into graph added ShanonB

        foodHashTable.insert(food->getDescription(), *food); // Function takes in description of the food item in csv and then the food item
    }

    /*=== Main logic loop ===*/
    while (true) {
        // Prompt user for input (search a food item)
        displayMenu();
        // Get the description from user
        std::string userInput;
        std::getline(std::cin, userInput);

        // Exit program or display nutrient menu
        if (userInput == "2") {
            // Give user option to exit the program (exit while loop)
            std::cout << "You have exited FoodSearch." << std::endl;
            break;
        }
        if (userInput == "1") {
            // Prompt food to search and store in input string
            std::cout << "Enter a food to search: ";
            std::string input;
            std::getline(std::cin, input);

            /*=== Building Data Structures + Search ===*/
            // Ask user what data structure to build: 1. HashTable, 2. Graph
            // Choose from Graph of Hash Table data structure
            std::cout << "Choose a data structure to search with: " << endl;
            std::cout << "1. Hash Table\n";
            std::cout << "2. Graph\n";
            std::cout << "Enter 1 or 2 to make a selection." << endl;

            std::string search;
            std::getline(std::cin, search);

            // Vector to store results from search
            std::vector<const Food*> results;

            // If hash table
            if (search == "1") {
                // Vector for storing all matches
                std::vector<Food> matches;

                /*=== Exact Match Search: if there is an exact match, O(1) complexity ===*/
                auto match = foodHashTable.getFood(search);
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
                    for (char i : input) {
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
            // Get items using hashtable search function
            // Push back onto vector
            // If graph
            // Get items using graph search function
            // Push back onto vector

            /*=== Displaying Search Results ===*/
            // Display vector items to console
            // Write items to a CSV (in a pair)
            // Prompt user to select a filter (menu of nutrient types)
            displayNutrientMenu();
        }
    }
        


    return 0;
}
