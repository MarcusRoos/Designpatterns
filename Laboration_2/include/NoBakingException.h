//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_NOBAKINGEXCEPTION_H
#define DT063G_NOBAKINGEXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

class NoBakingException : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Couldn't find any more recipes";
    }
};

#endif //DT063G_NOBAKINGEXCEPTION_H
