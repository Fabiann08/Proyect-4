#include "Dealer.h"

void Dealer::setBrandLength(string aBrand)
{
	if (aBrand.length() + 2 > brandLength)
		this->brandLength = aBrand.length() + 2;
}

void Dealer::reduceBrandLength()
{
	int holder = 0;
	for (int i = 0; i < count; i++)
	{
		if (inventory[i]->getBrand().length() + 2 > holder)
		{
			holder = inventory[i]->getBrand().length() + 2;
		}
	}
	if (holder < brandLength)
		this->brandLength = holder;
}

void Dealer::setModelLength(string aModel)
{
	if (aModel.length() + 2 > modelLength)
		this->modelLength = aModel.length() + 2;
}

void Dealer::reduceModelLength()
{
	int holder = 0;
	for (int i = 0; i < count; i++)
	{
		if (inventory[i]->getModel().length() + 2 > holder)
		{
			holder = inventory[i]->getModel().length() + 2;
		}
	}
	if (holder < modelLength)
		this->modelLength = holder;
}

void Dealer::orderInventory()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (inventory[j]->getBrand().compare(inventory[j + 1]->getBrand()) > 0)//order by Brand
			{
				Car* temp = inventory[j];
				inventory[j] = inventory[j + 1];
				inventory[j + 1] = temp;
			}
			if (inventory[j]->getModel().compare(inventory[j + 1]->getModel()) > 0)//order by Model
			{
				Car* temp = inventory[j];
				inventory[j] = inventory[j + 1];
				inventory[j + 1] = temp;
			}
			if (inventory[j]->getSerialNumber().compare(inventory[j + 1]->getSerialNumber()) > 0)//Order by Serial Number
			{
				Car* temp = inventory[j];
				inventory[j] = inventory[j + 1];
				inventory[j + 1] = temp;
			}
		}
	}
}

Dealer::Dealer()
{
	count = 0;
	name = "";
	brandLength = 0;
	inventory = nullptr;
}

Dealer::Dealer(string aName)
{
	count = 0;
	name = aName;
	brandLength = 0;
	inventory = nullptr;
}

void Dealer::addCar(string aBrand, string aModel)
{
	count++;//increment count + 1
	Car** temp = new Car * [count];//Create temporary Array
	for (int i = 0; i < count - 1; i++)
	{
		temp[i] = new Car(*inventory[i]);//copy over to temp
	}
	//for (int i = 0; i < count - 1; i++)//delete inventory
	//{
	//	delete inventory[i];
	//}
	//delete[] inventory;
	inventory = temp;
	inventory[count - 1] = new Car(aBrand, aModel);//create new Car object inside inventory array
	inventory[count - 1]->setBrand(aBrand);//sets brand name to the new Car object
	inventory[count - 1]->setModel(aModel);//sets model name to the new Car object

	setBrandLength(aBrand);//sets new brand length if any
	setModelLength(aModel);//sets new model length if any
	orderInventory();//orders cars alphabetically by code
}

void Dealer::sellCar(string aBrand, string aModel)
{
	if (findCar(aBrand, aModel) != -1)
	{
		Car** temp = new Car * [count];
		for (int i = 0, j = 0; i < count; i++)
		{
			if (i + 1 != findCar(aBrand, aModel))
			{
				temp[j] = new Car(*inventory[i]);
				j++;
			}
		}
		//for (int i = 0; i < count; i++)
		//{
		//	delete inventory[i];
		//}
		//delete[] inventory;
		inventory = temp;
		cout << "\nCar " << aBrand << " " << aModel << " has been sold!\n";

		count--;
		reduceBrandLength();//sets new brand length if any
		reduceModelLength();//sets new model length if any
	}
	else
	{
		cout << "\n**ERROR - Car " << aBrand << " " << aModel << " is NOT in the inventory!**\n";
	}
}

void Dealer::sellCar(string aSerialNumber)
{
	if (findCar(aSerialNumber) != -1)
	{
		Car** temp = new Car * [count];
		for (int i = 0, j = 0; i < count; i++)
		{
			if (i + 1 != findCar(aSerialNumber))
			{
				temp[j] = new Car(*inventory[i]);
				j++;
			}
		}
		//for (int i = 0; i < count; i++)
		//{
		//	delete inventory[i];
		//}
		//delete[] inventory;
		inventory = temp;
		cout << "\nCar " << aSerialNumber << " has been sold!\n";

		count--;
		reduceBrandLength();//sets new brand length if any
		reduceModelLength();//sets new model length if any
	}
	else {
		cout << "\n**ERROR - Car " << aSerialNumber << " is NOT in the inventory!**\n";
	}
}

int Dealer::findCar(string aBrand, string aModel) const
{
	for (int i = 0; i < count; i++)//iterates through the array
	{
		if (inventory[i]->getBrand() == aBrand && inventory[i]->getModel() == aModel)//compares given brand and model with brands and models inside array
			return i + 1;//returns index in array + 1
	}
	return -1;//does not find Car object with given brand and model
}

int Dealer::findCar(string aSerialNumber) const
{
	for (int i = 0; i < count; i++)//iterates through the array
	{
		if (inventory[i]->getBrand() == aSerialNumber)//compares given brand and model with brands and models inside array
			return i + 1;//returns index in array + 1
	}
	return -1;//does not find Car object with given brand and model
}

void Dealer::printBrandInventory() const
{
	cout << "\nDealer " << name << " has " << count << " of cars in inventory.\n\n";
	cout << left << setw(brandLength) << "BRAND" << " " << setw(5) << "COUNT\n";
	for (int i = 0; i < count; i++)
		cout << left << setw(brandLength) << inventory[i]->getBrand() << " " << setw(5) << i + 1 << "\n";
}

void Dealer::printModelInventory() const
{
	if (count != 0) {
		cout << "\nDealer " << name << " has " << count << " of cars in inventory.\n\n";
		cout << left << setw(brandLength) << "BRAND" << " "
			<< setw(modelLength) << "MODEL" << " "
			<< setw(5) << "COUNT\n";
		for (int i = 0; i < count; i++)
			cout << left << setw(brandLength) << inventory[i]->getBrand() << " "
			<< setw(modelLength) << inventory[i]->getModel() << " "
			<< setw(5) << i + 1 << "\n";
	}
}

void Dealer::printDetailedInventory() const
{
	if (count != 0) {
		cout << "\nDealer " << name << " has " << count << " of cars in inventory.\n\n";
		cout << left << setw(brandLength) << "BRAND" << " "
			<< setw(modelLength) << "MODEL" << " "
			<< setw(15) << "SERIAL NUMBER" << " "
			<< setw(5) << "COUNT\n";
		for (int i = 0; i < count; i++)
			cout << left << setw(brandLength) << inventory[i]->getBrand() << " "
			<< setw(modelLength) << inventory[i]->getModel() << " "
			<< setw(15) << inventory[i]->getSerialNumber() << " "
			<< setw(5) << i + 1 << "\n";
	}
}
