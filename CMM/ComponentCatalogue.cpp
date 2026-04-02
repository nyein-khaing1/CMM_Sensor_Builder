#include "ComponentCatalogue.h"
#include "ComponentCatalogue.h"
#include <iostream>
#include <iomanip>

ComponentCatalogue::ComponentCatalogue() {
    initializeCatalogue();
}

void ComponentCatalogue::initializeCatalogue() {
    // Initialize catalogue with provided components
    heads_.push_back(std::make_shared<Head>("Head", 37.0, 14.0));

    probes_.push_back(std::make_shared<Probe>("ProbeA", 45.0, 23.94));
    probes_.push_back(std::make_shared<Probe>("ProbeB", 62.0, 10.0));

    modules_.push_back(std::make_shared<Module>("ModuleA-1", 27.0, 23.94));
    modules_.push_back(std::make_shared<Module>("ModuleA-2", 65.0, 23.94));
    modules_.push_back(std::make_shared<Module>("ModuleA-3", 150.0, 23.94));
    modules_.push_back(std::make_shared<Module>("ModuleB-1", 19.5, 12.5));

    tips_.push_back(std::make_shared<Tip>("1mm x 20mm", 20.0, 16.2));
    tips_.push_back(std::make_shared<Tip>("3mm x 30mm", 30.0, 16.2));
    tips_.push_back(std::make_shared<Tip>("5mm x 50mm", 50.0, 16.2));
}

void ComponentCatalogue::displayCatalogue() const {
    std::cout << "\n~~~ Component Catalogue ~~~" << std::endl;
    std::cout << std::left << std::setw(15) << "Name"
        << std::setw(10) << "Type"
        << std::setw(13) << "Size(mm)" 
        << std::setw(12) << "CTE" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (const auto& head : heads_) head->display();
    for (const auto& probe : probes_) probe->display();
    for (const auto& module : modules_) module->display();
    for (const auto& tip : tips_) tip->display();
    std::cout << std::endl;
}

void ComponentCatalogue::displayComponentsByType(const std::string& type) const {
    std::cout << "\n=== Available " << type << "s ===" << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
        << std::setw(15) << "Name"
        << std::setw(10) << "Type"
        << std::setw(13) << "Size(mm)"
        << std::setw(12) << "CTE" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    if (type == "Head") {
        for (size_t i = 0; i < heads_.size(); ++i) {
            std::cout << std::left << std::setw(5) << i + 1;
            heads_[i]->display();
        }
    }
    else if (type == "Probe") {
        for (size_t i = 0; i < probes_.size(); ++i) {
            std::cout << std::left << std::setw(5) << i + 1;
            probes_[i]->display();
        }
    }
    else if (type == "Module") {
        for (size_t i = 0; i < modules_.size(); ++i) {
            std::cout << std::left << std::setw(5) << i + 1;
            modules_[i]->display();
        }
    }
    else if (type == "Tip") {
        for (size_t i = 0; i < tips_.size(); ++i) {
            std::cout << std::left << std::setw(5) << i + 1;
            tips_[i]->display();
        }
    }
    std::cout << std::endl;
}

std::shared_ptr<Head> ComponentCatalogue::getHead(int index) const {
    if (index >= 0 && index < static_cast<int>(heads_.size())) {
        return heads_[index];
    }
    return nullptr;
}

std::shared_ptr<Probe> ComponentCatalogue::getProbe(int index) const {
    if (index >= 0 && index < static_cast<int>(probes_.size())) {
        return probes_[index];
    }
    return nullptr;
}

std::shared_ptr<Module> ComponentCatalogue::getModule(int index) const {
    if (index >= 0 && index < static_cast<int>(modules_.size())) {
        return modules_[index];
    }
    return nullptr;
}

std::shared_ptr<Tip> ComponentCatalogue::getTip(int index) const {
    if (index >= 0 && index < static_cast<int>(tips_.size())) {
        return tips_[index];
    }
    return nullptr;
}

size_t ComponentCatalogue::getHeadCount() const {
    return heads_.size();
}

size_t ComponentCatalogue::getProbeCount() const {
    return probes_.size();
}

size_t ComponentCatalogue::getModuleCount() const {
    return modules_.size();
}

size_t ComponentCatalogue::getTipCount() const {
    return tips_.size();
}