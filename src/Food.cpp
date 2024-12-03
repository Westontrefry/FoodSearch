//
// Created by Weston Trefry on 11/30/24.
//

#include "Food.h"
#include <iostream>
#include <fstream>
#include <sstream>

// addded ShanonB
Food::Food(std::string name, float fiber, float protein, float sodium,     
           float sugars, float satFats, float energy)
    : _description(std::move(name)), _fiber(fiber), _protein(protein),
      _sodium(sodium), _sugars(sugars), _satFats(satFats), _energy(energy) {}

std::string Food::getDescription() const
{
    return _description;
}

float Food::getFiber() const
{
    return _fiber;
}

float Food::getProtein() const
{
    return _protein;
}

float Food::getSodium() const
{
    return _sodium;
}

float Food::getSugars() const
{
    return _sugars;
}

float Food::getSatFats() const
{
    return _satFats;
}

float Food::getEnergy() const
{
    return _energy;
}

unsigned int Food::getCount()
{
    return _count;
}

/// ***** added ShanonB

// Helper function to handle N/A entries in CSV, and float conversion (from string)
float convertToFloat(const std::string& token) {
    if (token == "N/A") {
        return 0.0f;
    }
    // More edge cases for "N/A" occurences
    if (token.find('N') != std::string::npos ||
        token.find('/') != std::string::npos ||
        token.find('A') != std::string::npos) {
        return 0.0f;
    }
    // All others converted to float with passed in value
    return stof(token);
}

// Read File implementation
std::vector<Food*> Food::readFile(const std::string& fileName) {
    // Vector to store food objects
    std::vector<Food*> foods;

    // Input stream instantiation, pass in FoodData.csv file
    std::ifstream foodFS(fileName);

    // Check to make sure opening file is successful
    if (!foodFS.is_open()) {
        std::cout << "Error opening file: " << fileName << std::endl;
        return foods;
    }

    std::string foodInfo;
    unsigned int count = 0;
    getline(foodFS, foodInfo); // skips header

    // Get each attribute as a token, convert token to data type
    while (getline(foodFS, foodInfo)) {
        // Create stream object
        std::istringstream stream(foodInfo);
        std::string token;

        // Read description until comma OUTSIDE of quotes (handles quotes within quotes)
        std::string description;
        bool insideQuotes = false;
        char c;

        // Loop through each char and build token one at a time
        while (stream.get(c)) {
            if (c == '"') {
                // Change inside quotes to false (no comma following)
                insideQuotes = !insideQuotes;
            }
            else if (c == ',' && !insideQuotes) {
                // Comma follows, ACTUAL delimiter
                break;
            }
            // Built description variable character by character until delimiter is reached
            description += c;
        }
        // Set description variable to private attribute
        _description = description;

        std::cout << "Description: " << _description << std::endl;

        // Convert token to floats for each nutrient amount
        getline(stream, token, ',');
        std::cout << "Fiber token: " << token << std::endl;
        _fiber = convertToFloat(token);

        getline(stream, token, ',');
        std::cout << "Protein token: " << token << std::endl;
        _protein = convertToFloat(token);

        getline(stream, token, ',');
        std::cout << "Sodium token: " << token << std::endl;
        _sodium = convertToFloat(token);

        getline(stream, token, ',');
        std::cout << "Sugars token: " << token << std::endl;
        _sugars = convertToFloat(token);

        getline(stream, token, ',');
        std::cout << "Saturated fats token: " << token << std::endl;
        _satFats = convertToFloat(token);

        getline(stream, token, ',');
        std::cout << "Energy token: " << token << std::endl;
        _energy = convertToFloat(token);

        // Construct food object using the values stored by each token variable
        Food* food = new Food(_description, _fiber, _protein, _sodium, _sugars, _satFats, _energy);
        // Push_back onto vector that stores all food objects from CSV
        foods.push_back(food);
        // Increment count to keep track of number of total food objects stored
        count++;
    }
    return foods;
}
