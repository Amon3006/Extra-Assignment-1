#include<iostream>
using namespace std;

class Test{
   
    private:
    int * i;
    int i2; 

    public:
    Test(int i,int i2){
        this->i= new int(i);
        this->i2 =i2;
    }
    void disply(){
        cout<<"i ="<<i<<endl;
        cout<<"i2 ="<<i2<<endl;
    }

};

class TestDerived: public Test{

    

}
int main(){

    Test t1(10,20);
    Test t2(40,30);

    t1 = t2;

    t1.disply();

}