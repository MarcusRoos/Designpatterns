//------------------------------------------------------------------------------
// PowerSourceAdapters.h DT063G Design Patterns With C++
// Definition of adapters classes that adapt various power sources / engines to
// the PowerSource interface. This will enable adaptees to be used
// polymorphically as PowerSource objects without any changes to the original
// classes.
//------------------------------------------------------------------------------

#pragma once

#include "PowerSource.h"
#include "V8Classic.h"
#include "GasTurbine.h"
#include "FuelCell.h"


/**
 * V8Classic object adapter
 */
class V8ClassicAD : public PowerSource {
 private:
    V8Classic v8;  // Adaptee

 public:
    V8ClassicAD() : PowerSource("V8") {}

    bool isRunning() const override;
    bool tryStart() override;
    void stop() override;
    bool setPower(int p = 0) override;
    bool incPower(int p = 10) override;
    bool decPower(int p = 10) override;
};


/**
 * GasTurbine object adapter
 */
class GasTurbineAD : public PowerSource {
 private:
    GasTurbine gt;  // Adaptee
 public:
    GasTurbineAD() : PowerSource("Gas turbine") {}

    bool isRunning() const override;
    bool tryStart() override;
    void stop() override;
    bool setPower(int p = 0) override;
    bool incPower(int p = 10) override;
    bool decPower(int p = 10) override;
};


/**
 * FuelCell class adapter
 */
class FuelCellAD : public PowerSource, private FuelCell {
 public:
    FuelCellAD() : PowerSource("Fuel cell") {}

    bool isRunning() const override;
    bool tryStart() override;
    void stop() override;
    bool setPower(int p = 0) override;
    bool incPower(int p = 10) override;
    bool decPower(int p = 10) override;
};
