//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_WHISPERER_H
#define DT063G_WHISPERER_H
#include "SoundProducer.h"
#include <iostream>

class Whisperer : public SoundProducer {
public:
    Whisperer();
    void makeSound() const override;
};

#endif //DT063G_WHISPERER_H
