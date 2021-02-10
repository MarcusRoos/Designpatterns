//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_RECIPES_H
#define DT063G_RECIPES_H

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

class Pizza : public BakingRecepy
{

public:
    Pizza();
    ~Pizza() override = default;
    void bakeIt() override;

};

class Scones : public BakingRecepy
{
public:
    Scones();

    ~Scones() override = default;
    void bakeIt() override;
};
class Sockerkaka : public BakingRecepy
{

public:
    Sockerkaka();
    ~Sockerkaka() override = default;
    void bakeIt() override;
};

class Kladdkaka : public BakingRecepy
{
public:
    Kladdkaka();
    ~Kladdkaka() override = default;
    void bakeIt() override;
};

#endif //DT063G_RECIPES_H
