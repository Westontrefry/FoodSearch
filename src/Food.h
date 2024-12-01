//
// Created by Weston Trefry on 11/30/24.
//

#ifndef FOOD_H
#define FOOD_H
#include <string>


class Food {
public:
    /*=== Constructors ===*/

    /*=== Getter Functions ===*/
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
    unsigned int count = 0;

    /*=== File Functions (for CSV) ===*/

    /*=== Search Functions ===*/

};



#endif //FOOD_H
