#include<iostream>
using namespace std;
/*10. Write a menu driven program to perform the following options using separate functions. Accept a number and then, do the following operations on this number:
1. Prime number or not
2. Odd or Even
3. Positive or Negative
4. Exit*/

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int choice;
    int number;

    do {
        cout << "Menu:" << endl;
        cout << "1. Check if prime" << endl;
        cout << "2. Check if odd or even" << endl;
        cout << "3. Check if positive or negative" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }

        cout << "Enter a number: ";
        cin >> number;

        switch (choice) {
            case 1:
                if (isPrime(number)) {
                    cout << number << " is a prime number." << endl;
                } else {
                    cout << number << " is not a prime number." << endl;
                }
                break;
            case 2:
                if (number % 2 == 0) {
                    cout << number << " is even." << endl;
                } else {
                    cout << number << " is odd." << endl;
                }
                break;
            case 3:
                if (number > 0) {
                    cout << number << " is positive." << endl;
                } else if (number < 0) {
                    cout << number << " is negative." << endl;
                } else {
                    cout << number << " is zero." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);

    return 0;
}