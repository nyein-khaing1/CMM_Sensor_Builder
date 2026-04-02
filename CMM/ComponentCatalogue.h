#ifndef COMPONENT_CATALOGUE_H
#define COMPONENT_CATALOGUE_H

#include "Component.h"
#include <vector>
#include <memory>

// Component Catalogue class
class ComponentCatalogue {
private:
    std::vector<std::shared_ptr<Head>> heads_;
    std::vector<std::shared_ptr<Probe>> probes_;
    std::vector<std::shared_ptr<Module>> modules_;
    std::vector<std::shared_ptr<Tip>> tips_;

    void initializeCatalogue();

public:
    ComponentCatalogue();

    void displayCatalogue() const;
    void displayComponentsByType(const std::string& type) const;

    // Getters for components
    std::shared_ptr<Head> getHead(int index) const;
    std::shared_ptr<Probe> getProbe(int index) const;
    std::shared_ptr<Module> getModule(int index) const;
    std::shared_ptr<Tip> getTip(int index) const;

    // Get counts
    size_t getHeadCount() const;
    size_t getProbeCount() const;
    size_t getModuleCount() const;
    size_t getTipCount() const;
};



#endif // COMPONENT_CATALOGUE_H
