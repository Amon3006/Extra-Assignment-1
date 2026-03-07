#include<iostream>
using namespace std;

/*3. Write a C++ program to process students' marks with the help of classes. 
The class has private variables for name, mark 1, mark 2, mark 3. 
It has two member functions - getdata() - to get input and result() -
 to print the results. All subjects mark must be >= 50 for pass otherwise fail. I
 mplement this program for n number of students.*/

class Student {
    private:
    string name;
    int mark1;
    int mark2;
    int mark3;

    public:
    void getdata() {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter mark 1: ";
        cin >> mark1;
        cout << "Enter mark 2: ";
        cin >> mark2;
        cout << "Enter mark 3: ";
        cin >> mark3;
    }

    void result() {
        if (mark1 >= 50 && mark2 >= 50 && mark3 >= 50) {
            cout << name << " has passed." << endl;
        } else {
            cout << name << " has failed." << endl;
        }
    }
};


int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        students[i].getdata();
    }

    for (int i = 0; i < n; i++) {
        students[i].result();
    }

    delete[] students;
    return 0;
}