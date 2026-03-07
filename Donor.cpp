#include<iostream>
using namespace std;

/*6. Create a Donor class which contains the members as 
name, age, blood group, and address. Include a method to display
 the donor's information. Write a C++ program to create an object 
 of the Donor class and display the donor's information.*/


class Donor {
    private:
    string name;
    int age;
    string bloodGroup;
    string address;

    public:
    Donor(){
        this->name = "";
        this->age = 0;
        this->bloodGroup = "";
        this->address = "";
    }

    Donor(const string name,const int age,const string bloodGroup,const string address){
        this->name = name;
        this->age = age;
        this->bloodGroup = bloodGroup;
        this->address = address;
    }

    void setName(string name){
        this->name = name;
    }

    void setAge(int age){
        this->age = age;
    }

    void setBloodGroup(string bloodGroup){
        this->bloodGroup = bloodGroup;
    }

    void setAddress(string address){
        this->address = address;
    }

    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
    }
};

int main()
{
    string name, bloodGroup, address;
    int age;

    cout << "Enter donor's name: ";
    getline(cin, name);
    cout << "Enter donor's age: ";
    cin >> age;
    cin.ignore(); // To ignore the newline character after age input
    cout << "Enter donor's blood group: ";
    getline(cin, bloodGroup);
    cout << "Enter donor's address: ";
    getline(cin, address);

    Donor donor(name, age, bloodGroup, address);
    cout << "\nDonor Information:" << endl;
    donor.displayInfo();

    return 0;
}