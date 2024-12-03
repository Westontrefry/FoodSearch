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

        // Parsing: description (string) & nutritional metrics (as floats)
        getline(stream, _description, ',');

        // Convert token to floats for each nutrient amount
        getline(stream, token, ',');
        _fiber = stof(token);
        getline(stream, token, ',');
        _protein = stof(token);
        getline(stream, token, ',');
        _sodium = stof(token);
        getline(stream, token, ',');
        _sugars = stof(token);
        getline(stream, token, ',');
        _satFats = stof(token);
        getline(stream, token, ',');
        _energy = stof(token);

        // Construct food object using the values stored by each token variable
        Food* food = new Food(_description, _fiber, _protein, _sodium, _sugars, _satFats, _energy);
        // Push_back onto vector that stores all food objects from CSV
        foods.push_back(food);
        // Increment count to keep track of number of total food objects stored
        count++;


    }


    return {};
}
