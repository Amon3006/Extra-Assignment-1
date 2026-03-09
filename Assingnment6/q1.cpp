#include <iostream>
using namespace std;
#include <cstring>
// 23. Create function for printing an array and call it from main (Employee array)
// store empid,name,sal, sort it on salary and display in sorted order of sal
// ask user whether to sort in ascending or descending order and do accordingly.
class Employe
{
private:
    int empid;
    string name;
    int sal;

public:
    Employe()
    {
        int empid = 0;
        string name = NULL;
        int sal = 0;
    }
    Employe(int empid, string name, int sal)
    {
        this->empid = empid;
        this->name = name;
        this->sal = sal;
    }
    void accept_data()
    {
        cout << "enter the empid" << endl;
        cin >> empid;
        cout << "Enter the string" << endl;
        cin >> name;
        cout << "Enter the sal" << endl;
        cin >> sal;
    }
    void display()
    {

        cout << "The employee is :" << this->empid << endl;
        cout << "The employee is :" << this->name << endl;
        cout << "The employee is :" << this->sal << endl;
    }
    int getsal()
    {
        return sal;
    }
};
void sort_Emp(Employe *e, int size, int options)
{
    if (options == 1)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (e[j].getsal() > e[j + 1].getsal())
                {
                    swap(e[j], e[j + 1]);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (e[j].getsal() < e[j + 1].getsal())
                {
                    swap(e[j], e[j + 1]);
                }
            }
        }
    }
}
void display_list(Employe *E, int size)
{

    for (int i = 0; i < size; i++)
    {
        E[i].display();
        cout << endl;
    }
}
int main()
{

    Employe e1(12, "LAkshya", 200000), e2(13, "Aman", 20000), e3(14, "KK", 31);
    Employe E_arra[] = {e1, e2, e3};


    cout << "Choose the option" << endl;
    cout << "1.Assceending for 1" << " " << "2.Descending for 2" << endl;
    int options;
    cin >> options;
    switch (options)
    {
    case 1:
        sort_Emp(E_arra, 3, 1);
        display_list(E_arra,3);
        break;
    case 2:
        sort_Emp(E_arra, 3, 2);
         display_list(E_arra,3);
     break;
    default:
        exit;
    }
}