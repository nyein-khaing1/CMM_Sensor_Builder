#ifndef SENSOR_H
#define SENSOR_H

#include "Component.h"
#include <memory>

//Sensor class holds the complete assembly
class Sensor {
private:
	// using smart pointer to manage memory automatically
	std::shared_ptr<Head> head_;
	std::shared_ptr<Probe> probe_;
	std::shared_ptr<Module> module_;
	std::shared_ptr<Tip> tip_;

public:
	Sensor() = default;

	void setHead(std::shared_ptr<Head> head);
	void setProbe(std::shared_ptr<Probe> probe);
	void setModule(std::shared_ptr<Module> module);
	void setTip(std::shared_ptr<Tip> tip);

	//return true if all four components are set
	bool isComplete() const;

	//calculate total length
	double getTotalLength() const;

	//calculate overall CTE
	double getOverallCTE() const;

	//display configuration
	void displayConfig() const;


	//getters for individual components
	std::shared_ptr<Head> getHead() const;
	std::shared_ptr<Probe> getProbe() const;
	std::shared_ptr<Module> getModule() const;
	std::shared_ptr<Tip> getTip() const;

};
#endif //SENSOR_H

