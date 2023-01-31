#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Car {
private:
	static unsigned short count;
	// count is the number of Car objects created
	string brand;
	string model;
	string serialNumber;
	string assignSerialNumber();
	// assignSerialNumber is a private method which considers
	// the brand, model, and count to create a 9-symbol string.
	// The format is first three letters of the brand, first three 
	// letters of the model and the 3-digit count value
	// If a Toyota Yaris is the first car added, the serial number 
	// would be TOYYAR001
	// If the brand and model fields have not been assigned a
	// value, the method DOES NOT create a serial number, and
	// returns the empty string
public:
	Car();
	// Assigns the empty string to all three fields, and 
	// increments count by 1
	Car(string, string);
	// The parameterized constructor increments count by 1
	// assigns the brand and model to the fields, and calls
	 // the assignSerialNumber method to create the serial number
	~Car();
	// The destructor prints the message
	// “The car [brand] [model] with serial number [serial number] 
	// has been sold”
	void setBrand(string); // sets brand value IFF not set before
	void setModel(string); // sets model value IFF not set before
	string getBrand() const; // If no brand, return empty string
	string getModel() const; // If no model, return empty string
	string getSerialNumber() const;
	// Returns the empty string if serial number not set
	void printCar(unsigned short, unsigned short);
	// printCar prints the car’s details in a table-like manner
	// using the format car_brand car_model serial number
	// It uses the parameters as the size of the brand and model 
	// fields, and prints N/A if the fields have no value
};
