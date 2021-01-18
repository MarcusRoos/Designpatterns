//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SOUNDPRODUCER_H
#define DT063G_SOUNDPRODUCER_H
#include <utility>
#include <string>

class SoundProducer {
private:
    std::string soundName;
public:
    SoundProducer() = default;
    explicit SoundProducer(std::string nameOfSound);
    virtual  ~SoundProducer() = default;
    virtual void makeSound() const = 0;
    std::string getSoundName() const { return soundName; }
};

#endif //DT063G_SOUNDPRODUCER_H
