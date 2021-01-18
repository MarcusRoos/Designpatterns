//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include <Uppgift1.h>

void Uppgift1::setSoundProducer(SoundProducer *sp) {
    soundproducer = sp;
}

void Uppgift1::saySomething() const {
    soundproducer->makeSound();
}

