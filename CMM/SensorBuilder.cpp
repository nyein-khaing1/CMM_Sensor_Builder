#include "SensorBuilder.h"
#include <iostream>
#include <limits>

void SensorBuilderApp::displayWelcome() {
    std::cout << "=== CMM Sensor Builder ===" << std::endl;
    std::cout << "Welcome to the Coordinate Measuring Machine Sensor Builder!" << std::endl;
    std::cout << "Build your sensor by selecting components from the catalogue." << std::endl;
}

void SensorBuilderApp::run() {
    displayWelcome();

    int choice;
    do {
        displayMenu();
        choice = getValidChoice(0, 7);

        switch (choice) {
        case 1:
            catalogue_.displayCatalogue();
            break;
        case 2:
            selectHead();
            break;
        case 3:
            selectProbe();
            break;
        case 4:
            selectModule();
            break;
        case 5:
            selectTip();
            break;
        case 6:
            sensor_.displayConfig();
            break;
        case 7:
            clearSensor();
            break;
        case 0:
            std::cout << "Thank you for using CMM Sensor Builder!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}

void SensorBuilderApp::displayMenu() {
    std::cout << "\n=== Main Menu ===" << std::endl;
    std::cout << "1. View Component Catalogue" << std::endl;
    std::cout << "2. Select Head" << std::endl;
    std::cout << "3. Select Probe" << std::endl;
    std::cout << "4. Select Module" << std::endl;
    std::cout << "5. Select Tip" << std::endl;
    std::cout << "6. View Current Sensor Configuration" << std::endl;
    std::cout << "7. Clear Sensor" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
}

void SensorBuilderApp::selectHead() {
    catalogue_.displayComponentsByType("Head");
    std::cout << "Select Head (1-" << catalogue_.getHeadCount() << "): ";
    int choice = getValidChoice(1, static_cast<int>(catalogue_.getHeadCount()));

    auto head = catalogue_.getHead(choice - 1);
    if (head) {
        sensor_.setHead(head);
        std::cout << "Head selected: " << head->getName() << std::endl;
    }
    else {
        std::cout << "Invalid selection." << std::endl;
    }
}

void SensorBuilderApp::selectProbe() {
    catalogue_.displayComponentsByType("Probe");
    std::cout << "Select Probe (1-" << catalogue_.getProbeCount() << "): ";
    int choice = getValidChoice(1, static_cast<int>(catalogue_.getProbeCount()));

    auto probe = catalogue_.getProbe(choice - 1);
    if (probe) {
        sensor_.setProbe(probe);
        std::cout << "Probe selected: " << probe->getName() << std::endl;
    }
    else {
        std::cout << "Invalid selection." << std::endl;
    }
}

void SensorBuilderApp::selectModule() {
    catalogue_.displayComponentsByType("Module");
    std::cout << "Select Module (1-" << catalogue_.getModuleCount() << "): ";
    int choice = getValidChoice(1, static_cast<int>(catalogue_.getModuleCount()));

    auto module = catalogue_.getModule(choice - 1);
    if (module) {
        sensor_.setModule(module);
        std::cout << "Module selected: " << module->getName() << std::endl;
    }
    else {
        std::cout << "Invalid selection." << std::endl;
    }
}

void SensorBuilderApp::selectTip() {
    catalogue_.displayComponentsByType("Tip");
    std::cout << "Select Tip (1-" << catalogue_.getTipCount() << "): ";
    int choice = getValidChoice(1, static_cast<int>(catalogue_.getTipCount()));

    auto tip = catalogue_.getTip(choice - 1);
    if (tip) {
        sensor_.setTip(tip);
        std::cout << "Tip selected: " << tip->getName() << std::endl;
    }
    else {
        std::cout << "Invalid selection." << std::endl;
    }
}

void SensorBuilderApp::clearSensor() {
    sensor_ = Sensor();
    std::cout << "Sensor configuration cleared." << std::endl;
}

int SensorBuilderApp::getValidChoice(int min, int max) {
    int choice;
    while (true) {
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between "
                << min << " and " << max << ": ";
        }
        else if (choice < min || choice > max) {
            std::cout << "Invalid choice. Please enter a number between "
                << min << " and " << max << ": ";
        }
        else {
            break;
        }
    }
    return choice;
}