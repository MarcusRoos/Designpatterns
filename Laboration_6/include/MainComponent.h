//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_MAINCOMPONENT_H
#define DT063G_MAINCOMPONENT_H
#include <string>

class MainComponent{
public:
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    virtual ~MainComponent() = default;
};

#endif //DT063G_MAINCOMPONENT_H
