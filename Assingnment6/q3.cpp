#include <iostream>
using namespace std;
#include <string>
#include<cstring>

/*
28. create following classes using Inheritance
and test whether you can create objects of all classes,
and also check whether you can call functions of the classes

Design a system for XYZ Bank for storing account details,
Every account will have type either saving account or current account or demat account
For every account interest rate and minimum balance need to be stored.
Interest rate for saving account is 4% and for current account 1%
Minimum balance for saving account will be 20000 and current account will be 1000
For each account store account holder details(fname, lname, mobile, email)

If it’s a saving account, then store chequebooknumber
If current account then store number of transactions/day, number of transactions will be different
for every account based on average annual balance in the account and will keep on changing based
on how customer maintains the balance in the account.

For demat account store share details, for every share store name, number of shares buying price,
date of purchase, selling price, date of selling.

*/

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date(){
        day =0;
        month =0;
        year =0;
    }
    Date(int day,int months, int year){
        this->day=day;
        this->year=year;
        this->month=month;
    }
    Date(string s){
        int res = s.find("/");
  	    int res1 = s.find("/",res+1);
        day = stoi(s.substr(0,2));
        month=stoi(s.substr(res+1,2));
        year = stoi(s.substr(res1+1,4));
    }

    void display(){
        cout<<day<<'/'<<month<<'/'<<year;
    }



};


class Account
{
private:
    static int count;
    int id;

protected:
    string fname;
    string lname;
    int mobile;
    string email;
    int balance = 0;
    Date date;

public:
    Account()
    {
        this->fname = "\0";
        this->lname = "\0";
        this->mobile = 0;
        this->email = "\0";
    }
    Account(string fname, string lname, int mobile, string email)
    {
        this->fname = fname;
        this->lname = lname;
        this->mobile = mobile;
        this->email = email;
        count++;
        //cout<<"I am in parameterized constructor"<<this->fname<<this->lname;
    }
    int getcount(){
        return count;
    }

    void display(){
    cout<<"Account id :"<<this->count;
    cout<<"first name :"<<this->fname<<endl;
    cout<<"last name :"<<this->lname<<endl;
    cout<<"email :"<<this->email<<endl;
    cout<<"mobile :"<<this->mobile<<endl;
    }
};
int Account::count = 6800;


class Saving : public Account
{
private:
    const double intrest_rate = 0.04;
    const int Minimum_balance = 20000;
    int cheqbookno;
    void   genrate_cheqbookno(){
        cheqbookno=getcount()*200;
    }

public:
    Saving()
    {
        Account();
        int cheqbookno;
    }
    Saving( string fname, string lname, int mobile, string email):Account(fname,lname,mobile,email)
    {
        genrate_cheqbookno();
    }

    bool deposit(int ammount){
        balance+=ammount;
        return true;

    }

    bool withdrawal(int ammount){
        if(balance - ammount>Minimum_balance){
            balance -= ammount;
            return true;
        } 
        return false;

    }

    void display(){
    Account::display();
    cout<<"checqbook no :"<<cheqbookno<<endl;
    }

};
class Current : public Account
{
private:
    const double intrest_rate = 0.01;
    const int Minimum_balance = 1000;
    //     number of transactions will be different
    // for every account based on average annual balance in the account and will keep on changing based
    // on how customer maintains the balance in the account.
    int tranc = 20;

public:
    Current(){}
    Current(string fname, string lname, int mobile, string email):Account(fname,lname,mobile,email){
        
    }

    bool deposit(int ammount){
        balance+=ammount;
            
        return true;

    }

    bool withdrawal(int ammount){
        if(balance - ammount>Minimum_balance){
            balance -= ammount;
            return true;
        } 
        return false;

    }
    void display(){
    Account::display();
    }


};
class Share
{
private:
    int price;
    string name;
    Date  pdate ;
    Date sdate ;

public:
    Share()
    {  
        name= "\0";
        price = 0;
    }
    Share(string name,int price,Date d1)
    {
        this->name = name;
        this->price = price;

    }
    
    void display(){
        cout<<"name : "<<name<<endl;
        cout<<"price: "<<price<<endl;

    }};


class Demat : public Account, public Share
{
private:
int no_of_share = 0; 
Share share_arr[100];


public:
    // Demat(){}
    Demat(string fname, string lname, int mobile, string email): Account(fname, lname, mobile, email)
    { }

    void BuyShare(Share s1){
        share_arr[no_of_share++] = s1;
    }

    void display(){
        int num = no_of_share;
        Account::display();
        cout<<"shares he has:"<<endl;
        while (num)
        {
            share_arr[num-1].display();
            num -=1;
            cout<<endl;
        }
        
    }


};
int main()
{
Saving c1("lakshya", "vayas", 83093, "hello@.com");

c1.deposit(200000);
if(c1.withdrawal(10)){
    cout<<"transaction Successful";
}
else{
    cout<<"transaction unsuccessful";}
}
