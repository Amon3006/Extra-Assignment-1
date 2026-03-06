#include<iostream>
using namespace std;

/*11. Write a C++ program to reverse a given string.*/

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversedStr = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversedStr += str[i];
    }

    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}