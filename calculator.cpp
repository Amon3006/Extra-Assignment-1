#include<iostream>
using namespace std;
/*10. Create a simple calculator class which contains the members as two numbers and a choice for the operation to be performed. Write a C++ program that accepts the member data for one calculator class object from the keyboard. Then, ask the user to perform one of the following operations on those numbers:
Addition
Subtraction
Multiplication
Division
And finally display the result of the operation.*/

class Calculator {
    private:
    double num1;
    double num2;
    char operation;

    public:
    Calculator(){
        this->num1 =0;
        this->num2=0;
        this->operation='+';
    }

    Calculator(const double num1,const double num2,const char operation){
        this->num1 = num1;
        this->num2 = num2;
        this->operation = operation;
    }

    void setNum1(double num1){
        this->num1 = num1;
    }

    void setNum2(double num2){
        this->num2 = num2;
    }

    void setOperation(char operation){
        this->operation = operation;
    }

    double calculate(){
        switch (operation)
        {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    cout << "Error: Division by zero!" << endl;
                    return 0; // Return 0 or handle as needed
                }
            default:
                cout << "Invalid operation!" << endl;
                return 0; // Return 0 or handle as needed
        }
    }
};

int main()
{
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    Calculator calc(num1, num2, operation);
    double result = calc.calculate();
    cout << "Result: " << result << endl;

    return 0;
}