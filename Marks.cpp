#include <iostream>

int main() {
    int grade;
    float average;
    int loop;
    int sum;
    int valid_entry;
    int failures;

    sum = 0;
    failures = 0;

    for (loop = 0; loop < 5; loop = loop + 1) {
        valid_entry = 0;
        while (valid_entry == 0) {
            std::cout << "Enter mark (0-100): ";
            std::cin >> grade;
            if (grade >= 0 && grade <= 100) {
                valid_entry = 1;
            } else {
                std::cout << "Invalid input. Please enter a mark between 0 and 100." << std::endl;
            }
        }
        if (grade < 65) {
            failures++;
        }
        sum = sum + grade;
    }
    average = static_cast<float>(sum) / 5;
    std::cout << "Average mark: " << average << std::endl;
    std::cout << "Number of failures: " << failures << std::endl;
    return 0;
}