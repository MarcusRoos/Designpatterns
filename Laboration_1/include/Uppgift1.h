//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_UPPGIFT1_H
#define DT063G_UPPGIFT1_H

#include "Talker.h"
#include "SoundProducer.h"
#include <iostream>

class Uppgift1 : public Talker {
private:
    SoundProducer *soundproducer{};
public:
    Uppgift1() = default;
    ~Uppgift1() override = default;
    void setSoundProducer(SoundProducer *as);
    void saySomething() const override();
};

#endif //DT063G_UPPGIFT1_H
