//
// Created by Weston Trefry on 11/30/24.
//

#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <vector>

class Food {
public:
    /*=== Constructors ===*/
    // Default
    Food();
    // Parameterized constructor
    Food(std::string d, float fiber, float protein, float sodium,
        float sugars, float satFats, float energy);

    /*=== Getter Functions ===*/
    // Nutritional attributes
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] float getFiber() const;
    [[nodiscard]] float getProtein() const;
    [[nodiscard]] float getSodium() const;
    [[nodiscard]] float getSugars() const;
    [[nodiscard]] float getSatFats() const;
    [[nodiscard]] float getEnergy() const;
    // Get number of food objects instantiated
    unsigned int getCount();

    /*=== File Functions (for CSV) ===*/
    // Read CSV file function, create vector of food objects to store each object read (line by line)
    std::vector<Food*> readFile(const std::string& fileName);

    /*=== Search Functions ===*/
    // Keyword function to help with returning list of items containing user input

private:
    /*=== Food Attributes ===*/
    std::string description;
    float _fiber = 0.0f;
    float _protein = 0.0f;
    float _sodium = 0.0f;
    float _sugars = 0.0f;
    float _satFats = 0.0f;
    float _energy = 0.0f;

    // Count to keep track of the number of food objects instantiated
    unsigned int _count = 0;

};



#endif //FOOD_H
