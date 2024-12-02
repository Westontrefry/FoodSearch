//
// Created by Weston Trefry on 11/30/24.
//

#include "Food.h"
#include <fstream>


// addded ShanonB

unsigned int Food::count = 0;

Food::Food(std::string name, float fiber, float protein, float sodium,     
           float sugars, float satFats, float energy)
    : description(std::move(name)), fiber(fiber), protein(protein),
      sodium(sodium), sugars(sugars), satFats(satFats), energy(energy)
{
    ++count; 
}

std::string Food::getDescription() const
{
    return description;
}

float Food::getFiber() const
{
    return fiber;
}

float Food::getProtein() const
{
    return protein;
}

float Food::getSodium() const
{
    return sodium;
}

float Food::getSugars() const
{
    return sugars;
}

float Food::getSatFats() const
{
    return satFats;
}

float Food::getEnergy() const
{
    return energy;
}

unsigned int Food::getCount()
{
    return count;
}

/// ***** added ShanonB



// Read File implementation
std::vector<Food*> readFile(const std::string& fileName) {
    return {};
}
