#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
class Vichle{
    protected:
    int reg_no;
    int modelno;
    string manufacture;
    static int count;
    int year;
    public:
    Vichle(){
         reg_no=0;
         modelno=0;
         manufacture="/0";
         year=0;
    }
    Vichle(int reg_no,int modelno,string manufacture,int year){
        
        this->reg_no=reg_no;
        this->modelno=modelno;
        this->manufacture=manufacture;
        this->year=year;
       
    }
    virtual void display()=0;
    // inline string pirnt(
    //     string s="Reg no: " +to_string(reg_no)+
    //             "model no: "+to_string(modelno)+
    //             "manufacture : " +to_string(manufacture)+
    //             "year : "+to_string(year);
    //     return s;
    //);

};
int Vichle::count=0;
class Car:public Vichle{
    protected :
    string fueltype;
    public :
    Car(){
        fueltype="\0";
    
    }
    Car(int reg_no,int modelno,string manufacture,int year,string fueltype): Vichle( reg_no,modelno ,manufacture,year){    
   this->fueltype=fueltype;
    }
    void accept(){
       try{ cout<<"Enter the fuel type"<<endl;
        cin>>fueltype;   
        cout<<"Enter the registration number"<<endl;
        cin>>reg_no;
        if(reg_no==0){
            throw "reg not valid";
        }
        cout<<"Enter the model number "<<endl;
        cin>>modelno;
        cout<<"enter the manfuacture name "<<endl;
        cin>>manufacture;
        cout<<"Enter the year"<<endl;
        cin>>year;  
         count++;
    }
    catch(const char * c){
        cout<<c;
    }
    }
       
    
    void display(){
        cout<<this->reg_no<<endl;
        cout<<this->modelno<<endl;
        cout<<this->manufacture<<endl;
        cout<<this->year<<endl;
        cout<<this->fueltype<<endl;
        // cout<<pirnt();
        cout<<count;
    }


};
class Bike:public Vichle{
    private:
    string enginecap;
    public:
    Bike(){
        enginecap="\0";
    }
    Bike(int reg_no,int modelno,string manufacture,int year,string enginecap):Vichle( reg_no,modelno ,manufacture,year){
        this->enginecap=enginecap;
    }
    void display(){
        cout<<this->reg_no<<endl;
        cout<<this->modelno<<endl;
        cout<<this->manufacture<<endl;
        cout<<this->year<<endl;
        cout<<this->enginecap<<endl;
        cout<<"The numbeer of vichels are now: "<<count;
    }

    void accept(){
       try{ cout<<"Enter the engine capacity"<<endl;
        cin>>enginecap;   
        cout<<"Enter the registration number"<<endl;
        cin>>reg_no;
        if(reg_no==0){
            throw "Reg not valid";
         }
        cout<<"Enter the model number "<<endl;
        cin>>modelno;
        cout<<"enter the manfuacture name "<<endl;
        cin>>manufacture;
        cout<<"Enter the year"<<endl;
        cin>>year;  
        count++;

        }
        catch(const char *c){
            cout<<c;
        }

        
    }
   
};


void write_to_file(Vichle *v){
ofstream fout("file.txt",ios::binary);
fout.write(reinterpret_cast<char*>(v),sizeof(*v));
fout.close();
}


void read_from_file(Vichle *v){
Vichle *v1;
ifstream fout("file.txt",ios::binary);
fout.read(reinterpret_cast<char*>(v1),sizeof(*v));

Car *c2 = dynamic_cast<Car*>(v1);
Bike *b2 = dynamic_cast<Bike*>(v1);

if(c2){
    c2->display();
}
else if(b2){
    b2->display();
}
}


int main(){

int x;
cout<<"enter the number of vichles"<<endl;
cin>>x;


for(int i=0;i<x;i++){
    cout<<"Enter the choice"<<endl;
cout<<"C for car"<<"B for Bike"<<endl;
char ch;
cin>>ch;
Vichle *v;
switch(ch){
    case 'c': {
        Car c1;
        c1.accept();
        v=&c1;
        write_to_file(v);
        //v->display();
        break;}
        case 'b':{
            Bike b1;
            b1.accept();
            v=&b1;
            //v->display();
            break ;
        }
        default:{
     cout<<"Bye bye";}
   }
read_from_file(v);
}
}