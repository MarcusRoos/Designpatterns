//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_INGREDIENT_HPP
#define DT063G_INGREDIENT_HPP


#include <exception>
#include <stdexcept>
#include <utility>

class Ingredient
{
private:
    std::string name;
public:
    explicit Ingredient(std::string aName) : name(std::move(aName)) {}
    ~Ingredient() = default;
    std::string getName() const { return name; }
    explicit operator std::string() const { return name; }
    bool operator==(const Ingredient& rhs) const {
        return name == rhs.getName();
    }
    bool operator<(const Ingredient& rhs) const {
        return name < rhs.getName();
    }
};

#endif //DT063G_INGREDIENT_HPP
