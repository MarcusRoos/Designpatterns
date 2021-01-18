//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Whisperer.h"
#include "SoundProducer.h"

Whisperer::Whisperer(): SoundProducer("Whisperer") {};

void Whisperer::makeSound() const {
    std::cout << getSoundName() << "Ssch,hush,hush" << std::endl;
}
