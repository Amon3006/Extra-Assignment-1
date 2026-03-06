#include<iostream>
using namespace std;
/*9. Create Time Class which contains the members as hour, minute and second. Write a C++ program that accepts member data for one Time class object from the keyboard. Then, ask the user to perform one of the following functions to that Time object:
AddHours
AddMinutes
AddSeconds
And finally display the newly modified Time information.*/

class Time {
    private:
    int hour;
    int minute;
    int second;

    public:
    Time(){
        this->hour =0;
        this->minute=0;
        this->second=0;
    }

    Time(const int hour,const int minute,const int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    void setHour(int hour){
        this->hour = hour;
    }

    void setMinute(int minute){
        this->minute = minute;
    }

    void setSecond(int second){
        this->second = second;
    }

    void addHours(int h){
        this->hour += h;
        // if (this->hour >= 24) {
        //     this->hour %= 24; // Wrap around if hours exceed 23
        // }
    }

    void addMinutes(int m){
        this->minute += m;
        if (this->minute >= 60) {
            addHours(this->minute / 60); // Add extra hours
            this->minute %= 60; // Wrap around minutes
        }
    }

    void addSeconds(int s){
        this->second += s;
        if (this->second >= 60) {
            addMinutes(this->second / 60); // Add extra minutes
            this->second %= 60; // Wrap around seconds
        }
    }

    void displayTime(){
        cout << "Time: " << hour << "h " << minute << "m " << second << "s" << endl;
    }
};

int main()
{
    int hour, minute, second;
    cout << "Enter time (hour minute second): ";
    cin >> hour >> minute >> second;

    Time t(hour, minute, second);

    int choice;
    cout << "Choose an option to modify time:" << endl;
    cout << "1. Add Hours" << endl;
    cout << "2. Add Minutes" << endl;
    cout << "3. Add Seconds" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            int h;
            cout << "Enter hours to add: ";
            cin >> h;
            t.addHours(h);
            break;
        case 2:
            int m;
            cout << "Enter minutes to add: ";
            cin >> m;
            t.addMinutes(m);
            break;
        case 3:
            int s;
            cout << "Enter seconds to add: ";
            cin >> s;
            t.addSeconds(s);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    t.displayTime();

    return 0;
}