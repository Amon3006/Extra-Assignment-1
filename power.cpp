#include<iostream>
using namespace std;

double power(double n, int p=2){
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return n * power(n, p - 1);
    }
}


int main()
{
    double n;
    int p;

    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the power: ";
    cin >> p;

    double result = power(n, p);
    cout << n << " raised to the power of " << p << " is: " << result << endl;

    return 0;
}