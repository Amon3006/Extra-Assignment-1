#include<iostream>
using namespace std;


/*14.Create a C++ class for a stock item abstract data type.
 It should have the attributes of stock levels (an integer) 
 and unit price (a float). Define the methods to return the
  values of these two attributes and to set them using parameters. 
  Add two more methods to allow stock receipt and issues updating the 
  stocklevel as appropriate. Write a menu driven C++ program to solve the problem.*/
class Stock {
    private:
    int stockLevel;
    float unitPrice;

    public:
    Stock(){
        this->stockLevel = 0;
        this->unitPrice = 0.0;
    }

    Stock(const int stockLevel,const float unitPrice){
        this->stockLevel = stockLevel;
        this->unitPrice = unitPrice;
    }

    void setStockLevel(int stockLevel){
        this->stockLevel = stockLevel;
    }

    void setUnitPrice(float unitPrice){
        this->unitPrice = unitPrice;
    }

    int getStockLevel(){
        return stockLevel;
    }

    float getUnitPrice(){
        return unitPrice;
    }

    void receiveStock(int quantity){
        stockLevel += quantity;
    }

    void issueStock(int quantity){
        if(quantity > stockLevel){
            cout << "Not enough stock to issue." << endl;
        } else {
            stockLevel -= quantity;
        }
    }
};


int main()
{
    Stock item;
    int choice, quantity;
    float price;

    do {
        cout << "Menu:" << endl;
        cout << "1. Set Stock Level" << endl;
        cout << "2. Set Unit Price" << endl;
        cout << "3. Receive Stock" << endl;
        cout << "4. Issue Stock" << endl;
        cout << "5. Display Stock Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter stock level: ";
                cin >> quantity;
                item.setStockLevel(quantity);
                break;
            case 2:
                cout << "Enter unit price: ";
                cin >> price;
                item.setUnitPrice(price);
                break;
            case 3:
                cout << "Enter quantity to receive: ";
                cin >> quantity;
                item.receiveStock(quantity);
                break;
            case 4:
                cout << "Enter quantity to issue: ";
                cin >> quantity;
                item.issueStock(quantity);
                break;
            case 5:
                cout << "Stock Level: " << item.getStockLevel() << endl;
                cout << "Unit Price: $" << item.getUnitPrice() << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);

    return 0;
}

