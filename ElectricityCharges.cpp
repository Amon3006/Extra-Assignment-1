#include<iostream>
using namespace std;
/*7. Create an Electricity Charges class which contains the members as units consumed and a method to calculate the electricity bill based on the following criteria:
- For the first 100 units: Rs. 1.20 per unit
- For the next 100 units: Rs. 2.00 per unit
- For units above 200: Rs. 3.00 per unit
Write a C++ program that accepts the units consumed from the keyboard and displays the total electricity bill.*/


class ElectricityCharges {
    private:
    int unitsConsumed;

    public:
    ElectricityCharges(){
        this->unitsConsumed =0;
    }

    ElectricityCharges(const int unitsConsumed){
        this->unitsConsumed = unitsConsumed;
    }

    void setUnitsConsumed(int unitsConsumed){
        this->unitsConsumed = unitsConsumed;
    }

    double calculateBill(){
        double billAmount = 0.0;

        if (unitsConsumed <= 100) {
            billAmount = unitsConsumed * 1.20;
        } else if (unitsConsumed <= 200) {
            billAmount = (100 * 1.20) + ((unitsConsumed - 100) * 2.00);
        } else {
            billAmount = (100 * 1.20) + (100 * 2.00) + ((unitsConsumed - 200) * 3.00);
        }

        return billAmount;
    }
};

int main()
{
    int units;
    cout << "Enter the units consumed: ";
    cin >> units;

    ElectricityCharges bill(units);
    double totalBill = bill.calculateBill();
    cout << "Total electricity bill: Rs. " << totalBill << endl;

    return 0;
}