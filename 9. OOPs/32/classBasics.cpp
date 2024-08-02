#include<iostream>
using namespace std;

class Animal{

    // state or properties
    private:
    int weight;

    public:
    int age;
    string name;

    // DEFAULT CONSTRUCTOR
    Animal(){
        this->age=0;
        this->weight=0;
        this->name="";
        cout<<"Constructor Called !"<<endl;
    }

    // PARAMETERISED CONSTRUCTOR
    Animal(int age){
        this->age=age;
        cout<<"Parametrized constructor Called !"<<endl;
    }

    Animal(int age , int weight){
        this->age=age;
        this->weight=weight;
        cout<<"Parametrized constructor II Called !"<<endl;
    }

    Animal(int age , int weight , string name){
        this->age=age;
        this->weight=weight;
        this->name = name;
        cout<<"Parametrized constructor III Called !"<<endl;
    }

    // COPY CONSTRUCTOR
    Animal(Animal& obj){
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout<<"COPY COSTRUCTOR CALLED"<<endl;
    }
    

    // behaviour
    void eat(){
        cout<<"Eating"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    int getWeight(){
        return weight;
    }

    void setWeight(int weight){
        this->weight = weight; // this-> weight is signifies to above declared at line 8
    }

    void print(){
        cout<<this->age<<" "<<this->weight<<" "<<this->name<<endl;
    }

    // DESTRUCTOR
    ~Animal(){
        cout<<"I am inside destructor"<<endl;
    }

};

int main(){
    // object creation 

    // STATIC MEMEORY ALLOCATION
    // Animal ram;

    // ram.age=12;
    // ram.name="LION";

    // cout<<"Age of ram is : "<<ram.age<<endl;
    // cout<<"Name of ram is : "<<ram.name<<endl;

    // // calling functions
    // ram.eat();

    // ram.sleep();

    // // to access private members
    // ram.setWeight(101);
    // cout<<"Wieght of ram is : "<<ram.getWeight()<<endl;


    // DYNAMIC MEMEORY ALLOCATION
    // Animal* ram = new Animal; // pointer

    // (*ram).age=12;
    // (*ram).name="LION";
    // cout<<"Age of ram is : "<<ram->age<<endl;
    // cout<<"Name of ram is : "<<ram->name<<endl;

    // // // ALTERNATIVE 

    // ram->age = 18;
    // ram->name = "KUTA";
    // cout<<"Age of ram is : "<<ram->age<<endl;
    // cout<<"Name of ram is : "<<ram->name<<endl;
    // ram->eat();

    // ram->sleep();

    // CONSTRUCTORS PASSING
    // Animal a(100);
    // Animal* b = new Animal(100);
    // Animal c(100 , 10);
    // Animal d(100 , 10 , "ram");

    // COPYING CONSTRUCTORS: 
    // 1st method
    // Animal f = a;

    // // 2nd method
    // Animal g(f);


    // Copy Constructor usage
    // Animal a;
    // a.age = 10;
    // a.setWeight(101);
    // a.name = "RAMANUJAN";

    // Animal b = a;
     
    // cout<<"a-> ";
    // a.print();

    // cout<<"b-> ";
    // b.print();

    // a.name[0] = 'L';
    // cout<<"a-> ";
    // a.print();

    // cout<<"b-> ";
    // b.print();

    // Static->automatically->destructor called
    // Animal a;
    // a.age = 5;

    // Dynamic->manually->destructor called
    // Animal *b = new Animal;
    // b->age = 12; 

    // // manually calling
    // delete b;
return 0;
}