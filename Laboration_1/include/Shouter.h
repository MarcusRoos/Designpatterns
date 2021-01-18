//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SHOUTER_H
#define DT063G_SHOUTER_H

#include "SoundProducer.h"
#include <iostream>

// Shouter class, extends SoundProducer, overrides makeSound
class Shouter : public SoundProducer {
public:
    Shouter();
    void makeSound() const override;
};

#endif //DT063G_SHOUTER_H
