#ifndef COMPONENT_H
#define COMPONENT_H


#include<string>
#include<iostream>
#include <iomanip>

//Base Component Class
//Initializing the component with name, type, size and cte
class Component {
public:
	Component(
		const std::string& name,
		const std::string& type,
		double size,
		double cte);
	// using base-class pointer
	virtual ~Component() = default;


	//using getter method to get access private/protected attributes
	const std::string& getName() const;
	const std::string& getType() const;
	double getSize() const;
	double getCte() const;

	virtual void display() const;

protected:
	std::string name_;
	std::string type_;
	double size_;
	double cte_;

};

//Inherit from Component
class Head : public Component {
public:
	Head(const std::string& name, double size, double cte);
};

class Probe : public Component {
public:
	Probe(const std::string& name, double size, double cte);
};

class Module : public Component {
public:
	Module(const std::string& name, double size, double cte);
};

class Tip : public Component {
public:
	Tip(const std::string& name, double size, double cte);
};

#endif // !COMPONENT_H



