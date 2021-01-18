//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_TALKER_H
#define DT063G_TALKER_H

// Talker class, binds the calls together
class Talker {
public:
    Talker() = default;
    virtual ~Talker() = default;
    virtual void saySomething() const = 0;
};

#endif //DT063G_TALKER_H
