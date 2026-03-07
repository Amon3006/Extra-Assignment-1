#include<iostream>
using namespace std;
/*7. An electricity board charges the following rates to domestic users:
For the first 100 units -. 5.5P per unit
For next 200 units -. 7.25P per unit
Beyond 300 units - *. 8.75P per unit
All users are charged a minimum of ₹. 60.
If the total amount is more than. 750 then an additional surcharge of 10% is added on the higher slab units.
Write a C++ program to read the names of users and number of units consumed and print out the charges with names.*/


class ElectricityCharges {
    private:
    string name;
    int units;

    public:
    ElectricityCharges(){
        this->name = "";
        this->units = 0;
    }

    ElectricityCharges(const string name,const double units){
        this->name = name;
        this->units = units;
    }

    void setName(string name){
        this->name = name;
    }

    void setUnits(double units){
        this->units = units;
    }

    double calculateCharges(){
        double charges = 0.0;

        if (units <= 100) {
            charges = units * 5.5 / 100;
        } else if (units <= 300) {
            charges = (100 * 5.5 / 100) + ((units - 100) * 7.25 / 100);
        } else {
            charges = (100 * 5.5 / 100) + (200 * 7.25 / 100) + ((units - 300) * 8.75 / 100);
        }

        if (charges < 60) {
            charges = 60; // Minimum charge
        } else if (charges > 750) {
            charges += charges * 0.10; // Add surcharge
        }

        return charges;
    }
};

int main()
{
    string name;
    double units;

    cout << "Enter user's name: ";
    cin >> name;
    cout << "Enter number of units consumed: ";
    cin >> units;

    ElectricityCharges user(name, units);
    double totalCharges = user.calculateCharges();

    cout << "User: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Total Charges: Rs." << totalCharges << endl;

    return 0;
}