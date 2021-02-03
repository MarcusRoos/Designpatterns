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
    auto *whisper = new Whisperer();
    auto *shout = new Shouter();

    // Whisper
    uppgift1.setSoundProducer(whisper);
    uppgift1.saySomething();
    // Shout
    uppgift1.setSoundProducer(shout);
    uppgift1.saySomething();
    
    delete whisper;
    delete shout;

    pauseFunction();
    return 0;
}

