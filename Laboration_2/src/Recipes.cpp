//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Recipes.h"

Pizza::Pizza() : BakingRecepy("Pizza") {
        neededIng.emplace_back("oil");
        neededIng.emplace_back("yeast");
        neededIng.emplace_back("wheat-flour");
        neededIng.emplace_back("salt");
}

void Pizza::bakeIt() {
    std::cout << "Baking: " << getName() << std::endl << "Which require "
                                                         "the ingredients: ";
        for (const auto& ingExists : neededIng){
            std::cout << ingExists.getName() << ", ";
        }

        std::cout << std::endl << "Mash ingredients together, put topping on "
                                  "dough, keep in oven at "
                                  "225C for 10min." << std::endl << std::endl;
}

Scones::Scones() : BakingRecepy("Scones") {
    neededIng.emplace_back("oil");
    neededIng.emplace_back("baking-powder");
    neededIng.emplace_back("wheat-flour");
    neededIng.emplace_back("salt");
    neededIng.emplace_back("sugar");
    neededIng.emplace_back("milk");
}

void Scones::bakeIt() {
    std::cout << "Baking: " << getName() << std::endl << "Which require "
                                                         "the ingredients: ";
    for (const auto& ingExists : neededIng){
        std::cout << ingExists.getName() << ", ";
    }
    std::cout << std::endl << "Mash ingredients together, put dough in "
                              "oven at 225C for 10min."
              << std::endl << std::endl;
}

Sockerkaka::Sockerkaka() : BakingRecepy("Sockerkaka") {
    neededIng.emplace_back("egg");
    neededIng.emplace_back("sugar");
    neededIng.emplace_back("baking-powder");
    neededIng.emplace_back("wheat-flour");
    neededIng.emplace_back("marge");
    neededIng.emplace_back("lemon");
}

void Sockerkaka::bakeIt() {
    std::cout << "Baking: " << getName() << std::endl << "Which require "
                                                         "the ingredients: ";
    for (const auto& ingExists : neededIng){
        std::cout << ingExists.getName() << ", ";
    }
    std::cout << std::endl << "Mash ingredients together, put in oven "
                              "at 225C for 15min. " << std::endl
              << std::endl;
}

Kladdkaka::Kladdkaka() : BakingRecepy("Kladdkaka") {
    neededIng.emplace_back("egg");
    neededIng.emplace_back("sugar");
    neededIng.emplace_back("baking-powder");
    neededIng.emplace_back("wheat-flour");
    neededIng.emplace_back("salt");
    neededIng.emplace_back("marge");
    neededIng.emplace_back("cocoa-powder");
}

void Kladdkaka::bakeIt() {
    std::cout << "Baking: " << getName() << std::endl << "Which require "
                                                         "the ingredients: ";
    for (const auto& ingExists : neededIng){
        std::cout << ingExists.getName() << ", ";
    }
    std::cout << std::endl << "Mash ingredients together, "
                              "keep in oven at 200C for 10min."
              << std::endl << std::endl;
}
