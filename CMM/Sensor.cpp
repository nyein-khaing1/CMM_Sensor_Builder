#include "Sensor.h"
#include <iostream>
#include <iomanip>

// each setter accepts a shared_ptr to a components and assigns it to the corresponding private member

void Sensor::setHead(std::shared_ptr<Head> head) {
    head_ = head;
}

void Sensor::setProbe(std::shared_ptr<Probe> probe) {
    probe_ = probe;
}

void Sensor::setModule(std::shared_ptr<Module> module) {
    module_ = module;
}

void Sensor::setTip(std::shared_ptr<Tip> tip) {
    tip_ = tip;
}


// check if all components are set
//return true only if all four components are non-null 
bool Sensor::isComplete() const {
    return head_ && probe_ && module_ && tip_;
}

//calculate total length 
double Sensor::getTotalLength() const {
    if (!isComplete()) return 0.0;
    return head_->getSize() + probe_->getSize() + module_->getSize() + tip_->getSize();
}


double Sensor::getOverallCTE() const {
    if(!isComplete()) return 0.0;

    //calculate weighted average CTE based on component lengths
    double totalLength = getTotalLength();
    if (totalLength == 0.0) return 0.0;

    double weightedCTE = (head_->getCte() * head_->getSize() +
        probe_->getCte() * probe_->getSize() +
        module_->getCte() * module_->getSize() +
        tip_->getCte() * tip_->getSize()) / totalLength;

    return weightedCTE;
}

void Sensor::displayConfig() const {
    std::cout << "\n~~~ Current Sensor Configuration ~~~" << std::endl;
    std::cout << std::left << std::setw(16) << "Component"
        << std::setw(11) << "Type"
        << std::setw(13) << "Length"
        << std::setw(9) << "CTE" << std::endl;
    std::cout << std::string(50, '-') << std::endl;


    if (head_) head_->display();
    if (probe_) probe_->display();
    if (module_) module_->display();
    if (tip_) tip_->display();

    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Total Length: " << std::fixed << std::setprecision(3)
        << getTotalLength() << " mm" << std::endl;
    std::cout << "Overall CTE: " << std::fixed << std::setprecision(3)
        << getOverallCTE() << std::endl;
    std::cout << "Status: " << (isComplete() ? "Complete" : "Incomplete") << std::endl;

}

//returning smart pointers to each sensor component

std::shared_ptr<Head> Sensor::getHead() const {
    return head_;
}

std::shared_ptr<Probe> Sensor::getProbe() const {
    return probe_;
}

std::shared_ptr<Module> Sensor::getModule() const {
    return module_;
}

std::shared_ptr<Tip> Sensor::getTip() const {
    return tip_;
}