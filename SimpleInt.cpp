#include<iostream>
#include<cmath>
using namespace std;
 
/*1. Write a C++ program to calculate Simple and Compound interest.*/

double calculateSimpleInterest(double principal, double rate, int time) {
    return (principal * rate * time) / 100;
}

double calculateCompoundInterest(double principal, double rate, int time) {
    return principal * pow((1 + rate / 100), time) - principal;
}

int main() {
    double principal, rate;
    int time;

    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter annual interest rate (in %): ";
    cin >> rate;
    cout << "Enter time (in years): ";
    cin >> time;

    double simpleInterest = calculateSimpleInterest(principal, rate, time);
    double compoundInterest = calculateCompoundInterest(principal, rate, time);

    cout << "Simple Interest: " << simpleInterest << endl;
    cout << "Compound Interest: " << compoundInterest << endl;

    return 0;
}