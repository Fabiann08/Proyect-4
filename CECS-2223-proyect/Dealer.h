#pragma once
#include "Car.h"
class Dealer {
private:
	unsigned short count; // The number of cars in inventory
	string name;
	Car** inventory;
	unsigned short brandLength;
	void setBrandLength(string);
	// compares the length of the parameter + 2 with the current 
	// value for brandLength. If the value of the parameter + 2
	// is greater than the current value, changes it
	void reduceBrandLength();
	// checks the inventory array for the size of the largest 
	// brand length, and assigns it to brandLength if the value 
	// found is smaller
	unsigned short modelLength;
	void setModelLength(string);
	// compares the length of the parameter + 2 with the current 
	// value for modelLength. If the value of the parameter + 2
	// is greater than the current value, changes it
	void reduceModelLength();
	// checks the inventory array for the size of the largest 
	// model length, and assigns it to modelLength if the value 
	// found is smaller
	void orderInventory();
	// Orders the cars in inventory alphabetically, first by brand 
	// name, then by model name, and then by serial number.
public:
	Dealer(); // initializes numeric fields to 0, name to the
	Dealer(string); // initializes numeric fields to 0, name to 
	// the parameter’s value, and inventory to the null pointer
	void addCar(string, string);
	// Receives a car’s brand and model as parameters. Creates a 
	// new Car object and adds it to inventory, increments count,
	// and calls the setModelLength, setBrandLength, and 
	// orderInventory methods
	void sellCar(string, string);
	// Receives a car’s brand and model as parameters. Calls 
	// findCar to make sure there is a car with the same brand 
	// and model in inventory, if not the method ends. If found, 
	// removes the car from inventory, decrements count, invokes 
	// the Car object’s destructor and calls the 
	// reduceModelLength and reduceBrandLength methods.
	void sellCar(string);
	// Receives a car’s serial number as parameter. Calls 
	// findCar to make sure there is a car with the same serial 
	// number in inventory, if not the method ends. If found, 
	// removes the car from inventory, decrements count, invokes 
	// the Car object’s destructor and calls the 
	// reduceModelLength and reduceBrandLength methods.
	int findCar(string, string) const;
	// receives a car’s brand and model as parameters and 
	// searches the inventory for a car with the given brand and 
	// model names. If found, returns the index number of the 
	// first instance, otherwise, returns -1
	int findCar(string) const;
	// receives a car’s serial number as parameter and searches 
	// the inventory for the serial number. If found, returns the 
	// index number, otherwise, returns -1
	void printBrandInventory() const;
	// prints the count of cars per brand. First, it prints the
	// phrase “Dealer [name] has [quantity] of cars in inventory.”
	// It then prints a table with the headers BRAND and COUNT, 
	// using brandLength as the size of the BRAND column. If there
	// are no cars in inventory, the table (including the headers) 
	// is not printed.
	void printModelInventory() const;
	// prints the count of cars per model. First, it prints the
	// phrase “Dealer [name] has [quantity] of cars in inventory.”
	// It then prints a table with the headers BRAND, MODEL, and
	// COUNT, using brandLength as the size of the BRAND column, 
	// and modelLength as the size of the MODEL column. If there 
	// are no cars in inventory, the table (including the headers) 
	// is not printed.
	void printDetailedInventory() const;
	// Prints a detailed inventory. First, it prints the
	// phrase “Dealer [name] has [quantity] of cars in inventory.”
	// It then prints a table with the headers BRAND, MODEL, and
	// SERIAL NUMBER, using brandLength as the size of the BRAND 
	// column, and modelLength as the size of the MODEL column. 
	// If there are no cars in inventory the table (including 
	// the headers) is not printed.
};
