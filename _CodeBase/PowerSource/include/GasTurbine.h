//------------------------------------------------------------------------------
// GasTurbine.h DT063G Design Patterns With C++
// Definition of class GasTurbine, a very inventive, abstraction of a
// gas turbine
//------------------------------------------------------------------------------

#pragma once

class GasTurbine {
 private:
    const int MIN_START_PRESSURE = 30;
    int pressure;  // 0 .. 100 units
    bool running, compressors, burner;
    bool checkRunning();  // Set value of the booleab running

 public:
    GasTurbine();

    bool startCompressors();
    void stopCompressors();
    bool burnerOn();
    bool burnerOff();
    bool setCompressorPressure(int);
    int getCompressorPressure( ) { return pressure; }
    bool isRunning() const;
};

/**
     * To start a GasTurbine:
     * startCompressors()
     * setCompressorPressure(pressure)  // pressure >= MIN_START_PRESSURE
     *
     * ... to stop it:
     * setCompressorPressure(0);
     * stopCompressors();
     * burnerOff();
     *
     * A changes in pressure gives a change in Power
     */
