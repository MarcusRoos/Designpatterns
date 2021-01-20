//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_BAKERY_H
#define DT063G_BAKERY_H

#include <exception>
#include "NoBakingException.h"
#include "BakingRecepyManager.h"

class Bakery {

private:
    BakingRecepyManager bakingRecepyManager;
public:
    explicit Bakery(const std::string& pantryPath) :
    bakingRecepyManager(pantryPath) {}
    void addRecepy(BakingRecepy *recipe) {bakingRecepyManager.addNewRecipe(recipe);}
    void runBakery();
};




#endif //DT063G_BAKERY_H
