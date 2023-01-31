#include "Car.h"
unsigned short Car::count = 0;

string Car::assignSerialNumber()
{
    if (brand == "" || model == "")
    {
        this->serialNumber = ""; return this->serialNumber;
    }
    if (count < 10)
    {
        for (auto& serialNumber : serialNumber = brand.substr(0, 3) + model.substr(0, 3) + "00" + to_string(count)) serialNumber = toupper(serialNumber);
        return this->serialNumber;
    }
    if (count >= 10 && count < 100)
    {
        for (auto& serialNumber : serialNumber = brand.substr(0, 3) + model.substr(0, 3) + "0" + to_string(count)) serialNumber = toupper(serialNumber);
        return this->serialNumber;
    }
    if (count >= 100 && count < 1000)
    {
        for (auto& serialNumber : serialNumber = brand.substr(0, 3) + model.substr(0, 3) + to_string(count)) serialNumber = toupper(serialNumber);
        return this->serialNumber;
    }
}

Car::Car()
{
    this->brand = "";
    this->model = "";
    count++;
    assignSerialNumber();

}

Car::Car(string aBrand, string aModel)
{
    this->brand = aBrand;
    this->model = aModel;
    count++;
    assignSerialNumber();
}

Car::~Car()
{
    cout << "The car " << this->brand << " " << this->model << " with serial number " << this->serialNumber << " has been sold!\n";
}

void Car::setBrand(string aBrand)
{
    this->brand = aBrand;
}

void Car::setModel(string aModel)
{
    this->model = aModel;
}

string Car::getBrand() const
{
    return this->brand;
}

string Car::getModel() const
{
    return this->model;
}

string Car::getSerialNumber() const
{
    return this->serialNumber;
}

void Car::printCar(unsigned short aBrand, unsigned short aModel)
{
    cout << left << setw(aBrand) << brand << " " << setw(aModel) << model << " " << setw(15) << assignSerialNumber() << "\n";
}
