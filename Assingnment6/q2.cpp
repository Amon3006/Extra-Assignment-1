#include<iostream>
using namespace std;

/*
27. Create Student class and add rollNo and name in it. 
Create Accept() function which will takean array of Students as input,
but add only one object at a time in the array.(hint: maintain count)
Write one more function to display student data. This Display() function should receive Student
array.
*/

class Student{
    private:
    int rollNo;
    string name;

    public:
    Student(int rollNo = 0,string name= ""){
        this->rollNo = rollNo;
        this->name = name;
    }

    void display(){
        cout<<"Name :"<<name<<endl
            <<"rollNO :"<<rollNo<<endl;
    }


};


//StudentArray -> Student is "has a realtionship"
class StudentArray{ 
    private:
    Student* Sarr;
    int count =0;
    public:

    StudentArray(int size){
        Sarr = new Student[size];
    }

    void Accept(Student S){
    Sarr[count] = S;
    count++;
}

void display(){
    for(int i =0;i<count;i++){
        Sarr[i].display();
        cout<<endl;
    }
}
};



int main(){
    int size = 100;
    StudentArray Sarr1(size);

    Student s1(22,"aman");
    Student s2(94,"lakshaya");
    Sarr1.Accept(s1);
    Sarr1.Accept(s2);
    Sarr1.Accept(s2);
    Sarr1.Accept(s1);
    Sarr1.Accept(s2);
    Sarr1.Accept(s2);


    Sarr1.display();



    return 0;
}