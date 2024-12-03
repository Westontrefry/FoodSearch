//
// Created by Weston Trefry on 11/30/24.
//
#include <iostream>
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
        std::string userInput;

        if (userInput == "2") {
            break;
        }
        if (userInput == "1") {
            // Prompt user to select a filter (menu of nutrient types)
            std::cout << "Filter by nutrient: " << std::endl;
            std::cout << "1. Fiber\n 2. Protein \n 3. Sodium \n "
                         "4. Sugars \n 5. Saturated Fats \n";
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
