//------------------------------------------------------------------------------
// Lab1.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "Uppgift1.h"
#include "Management.h"
#include "memstat.hpp"
#include "Whisperer.h"
#include "Shouter.h"

int main() {
    Uppgift1 uppgift1;
    Whisperer *whisper = new Whisperer();
    Shouter *shout = new Shouter();

    // Whisper
    uppgift1.setSoundProducer(whisper);
    uppgift1.saySomething();
    // Shout
    uppgift1.setSoundProducer(shout);
    uppgift1.saySomething();

    pauseFunction();
    return 0;
}

