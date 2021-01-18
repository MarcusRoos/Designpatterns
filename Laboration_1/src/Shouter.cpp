//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Shouter.h"

Shouter::Shouter() : SoundProducer("Shout: ") {}

void Shouter::makeSound() const {
    std::cout << getSoundName() << "WOW YEEEH!!" << std::endl;
};
