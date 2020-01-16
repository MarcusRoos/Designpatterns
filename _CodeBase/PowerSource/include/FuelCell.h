//------------------------------------------------------------------------------
// FuelCell.h DT063G Design Patterns With C++
// Definition of class FuelCell, a very simple abstraction of a fuel cell
//------------------------------------------------------------------------------

#pragma once

// Charged by the fuel cell
class Ackumulator {
 private:
    bool charged;

 public:
    Ackumulator() : charged(false) {}
    void charge() { charged = true; }
    bool hasPower() const { return charged; }
};

// Used by the fuel cell
class PowerRegulator {
 private:
    Ackumulator *theBattery;
    int power;  // 0 .. 100 units

 public:
    explicit PowerRegulator(Ackumulator *ack) : theBattery(ack), power(0) {}
    bool setElectricPower(int);
    int getElectricPower() const;
};

class FuelCell {
 protected:
    bool active;
    Ackumulator battery;
    PowerRegulator regulator;
    const int MIN_POWER = 5;
 public:
    FuelCell() : active(false), regulator(&battery) {}
    void fuelOn();
    void fuelOff();
    bool isActive() const;
    bool setRegulator(int powerLevel);  // 0..100
};

/**
     * To start a FuelCell:
     * set power level to at least MIN_POWER, setRegulator,
     * turn on the fuel, fuelOn()
     *
     * ... to stop it:
     * regulator.setElectricPower(0);
     * fuelOff();
     *
     * Power is controlled by:
     * regulator.setElectricPower(int)
     */
