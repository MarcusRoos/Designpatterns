//------------------------------------------------------------------------------
// Ingredient.hpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::ostream;

class Ingredient {
 private:
    string name;

 public:
	explicit Ingredient(string name) : name(std::move(name)) {}

    string getName() const { return name; }

	explicit operator string() const { return name; }

	bool operator==(const Ingredient& rhs) const {
		return name == rhs.getName();
	}

    bool operator<(const Ingredient& rhs) const {
        return name < rhs.getName();
    }
};
