#ifndef SENSOR_BUILDER_APP_H
#define SENSOR_BUILDER_APP_H

#include "ComponentCatalogue.h"
#include "Sensor.h"

// Main application class
class SensorBuilderApp {
private:
    ComponentCatalogue catalogue_;
    Sensor sensor_;

    void displayMenu();
    void selectHead();
    void selectProbe();
    void selectModule();
    void selectTip();
    void clearSensor();

    // Helper methods
    int getValidChoice(int min, int max);
    void displayWelcome();

public:
    SensorBuilderApp() = default;
    void run();
};

#endif // SENSOR_BUILDER_APP_H