#include<iostream>
using namespace std;

/*13. Write a program in C++ to determine how many of the characters are vowels and how many are consonants in a given line of text. Also terminate the string when the input character encountered is other than the alphabets (a-z or A-Z) and Blank spaces.
Hint:
a. When the input string is 'C plus plus FOR BEGINNERS, TEST YOUR C plus plus PROGRAMMING STRENGTHS'. Program will consider the string 'C plus plus FOR BEGINNERS' only because ',' is encountered.
b. When the input string is 'C++ LEARINING IS NOT A PROBLEM'. Program will consider the character 'C' only because the '+' is encountered.*/

int main()
{
    char str[100];
    int vowelCount = 0, consonantCount = 0;

    cout << "Enter a line of text: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            ch = tolower(ch); // Convert to lowercase for uniformity

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowelCount++;
            }
            else
            {
                consonantCount++;
            }
        }
        else if (ch != ' ')
        {
            break; // Terminate on encountering non-alphabetic character
        }
    }
    cout << "Number of vowels: " << vowelCount << endl;
    cout << "Number of consonants: " << consonantCount << endl;

    return 0;
}