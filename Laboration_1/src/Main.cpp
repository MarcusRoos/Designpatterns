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

    uppgift1.setSoundProducer(new Whisperer);
    uppgift1.saySomething();
    uppgift1.setSoundProducer(new Shouter);
    uppgift1.saySomething();

    pauseFunction();
    return 0;
}

