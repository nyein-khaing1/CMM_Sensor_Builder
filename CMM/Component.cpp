#include "Component.h"

//Component base class implementation
Component::Component(const std::string& name, const std::string& type, double size, double cte)
    : name_(name), type_(type), size_(size), cte_(cte) {
}

//getter functions
//returning the reference to the component's name (for read only)
const std::string& Component::getName() const {
    return name_;
}

const std::string& Component::getType() const {
    return type_;
}

double Component::getSize() const {
    return size_;
}

double Component::getCte() const {
    return cte_;
}

//display function
void Component::display() const {
    std::cout << std::left << std::setw(15) << name_
        << std::setw(10) << type_
        << std::setw(13) << size_ 
        << std::setw(12) << cte_ << std::endl;
}

// Head class implementation
Head::Head(const std::string& name, double size, double cte)
    : Component(name, "Head", size, cte) {
}

// Probe class implementation
Probe::Probe(const std::string& name, double size, double cte)
    : Component(name, "Probe", size, cte) {
}

// Module class implementation
Module::Module(const std::string& name, double size, double cte)
    : Component(name, "Module", size, cte) {
}

// Tip class implementation
Tip::Tip(const std::string& name, double size, double cte)
    : Component(name, "Tip", size, cte) {
}