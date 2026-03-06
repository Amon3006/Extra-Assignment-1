#include<iostream>
using namespace std;
 
/*1. Write a C++ program to calculate Simple and Compound interest.*/

class SimpleInt {
    private:
    double principal;
    double rate;
    int time;

    public:
    SimpleInt(){
        this->principal =0;
        this->rate=0;
        this->time=0;
    }

    SimpleInt(const double principal,const double rate,const int time){
        this->principal = principal;
        this->rate = rate;
        this->time = time;
    }

    void setPrincipal(double principal){
        this->principal = principal;
    }

    void setRate(double rate){
        this->rate = rate;
    }

    void setTime(int time){
        this->time = time;
    }

    double calculateSimpleInterest(){
        return (principal * rate * time) / 100.0;
    }
};

int main()
{
    double principal, rate;
    int time;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the rate of interest: ";
    cin >> rate;
    cout << "Enter the time in years: ";
    cin >> time;

    SimpleInt si(principal, rate, time);
    double simpleInterest = si.calculateSimpleInterest();
    cout << "Simple Interest: " << simpleInterest << endl;

    return 0;
}