//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include <Uppgift1.h>
/*
 * Wasn't entirely sure if we were meant to use raw pointer or smart pointer
 * for this task, but due to UML-diagram showing
 * "+setSoundProducer(sp:SoundProducer *) I assumed we were meant to work with
 * either raw pointers, or it didn't matter. Nevertheless, I have worked out
 * the memory allocation and there are no leaks. */
void Uppgift1::setSoundProducer(SoundProducer *sp) {
    soundproducer = sp;
}

void Uppgift1::saySomething() const {
    soundproducer->makeSound();
}

