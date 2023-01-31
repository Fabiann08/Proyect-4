#include "Dealer.h"

char menu()
{
    char selection;
    cout << "\nSelect one of the following :\n"
        << "    1. Add a car to inventory\n"
        << "    2. Sell a car from inventory\n"
        << "    3. Find a car by brand and model\n"
        << "    4. Print the brand inventory\n"
        << "    5. Print the model inventory\n"
        << "    6. Print the detailed inventory\n"
        << "    7. Exit the application\n"
        << "    \n"
        << "    Your selection:";
    cin >> selection;
    return selection;
}

bool execute(char selection, Dealer& poli)
{
    string aBrand;
    string aModel;
    switch (selection)
    {
    case '1'://Add a car to Inventory
        cout << "\nInput Car brand to add: ";
        cin >> aBrand;
        cout << "Input Car Model to add: ";
        cin >> aModel;
        poli.addCar(aBrand, aModel);
        break;
    case '2'://Sell a car from Inventory
        cout << "\nInput Car brand to remove: ";
        cin >> aBrand;
        cout << "Input Car Model to remove: ";
        cin >> aModel;
        poli.sellCar(aBrand, aModel);
        break;
    case '3'://Find a car by Brand and Model
        cout << "\nInput Car brand to find: ";
        cin >> aBrand;
        cout << "Input Car Model to find: ";
        cin >> aModel;
        if (poli.findCar(aBrand, aModel) > -1)
            cout << "\nCar found in position " << poli.findCar(aBrand, aModel) << "\n";
        else
        {
            cout << "\nCar not Found!\n";
        }
        break;
    case '4'://Print the Brand Inventory
        poli.printBrandInventory();
        break;
    case '5'://Print the Model Inventory
        poli.printModelInventory();
        break;
    case '6'://Print the detailed Inventory
        poli.printDetailedInventory();
        break;
    case '7':
        return false;
        break;
    default:
        cout << "\nERROR! UNACCEPTABLE SELECTION! TRY AGAIN!\n";
    }
}

int main() {
    Dealer poli("Poli Auto Sales");
    while (execute(menu(), poli));
    system("pause"); // Visual Studio only!
    return 0;
}
