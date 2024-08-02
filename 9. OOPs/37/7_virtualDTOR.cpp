#include<iostream>
using namespace std;



class Base{
public:
    Base(){ 
        cout<<"base ctor"<<endl;
    }
    virtual ~Base(){ // if we make base's dtor virtual this will call derived's dtor
    // Jab base ka dtor call hone gya to usne bola nahi virutal hai yeah dtor nahi call krna dervied ka dtor
    // call kro. uske baad isko call kro. To iss way se puri destruction horhi haii
        cout<<"base dtor"<<endl;
    }
};



class Derived : public Base{
    int *a;
public:
    Derived(){
        a = new int[1000]; // without base virtual dtor this dtor is never called and in case the memory leak is there because a will never be deleted but now it is happening
        cout<<"Derived ctor"<<endl;
    }
    ~Derived(){
        delete[] a;
        cout<<"Derived dtor"<<endl;
    }
};

int main(){
    Base *b = new Derived();
    delete b;
return 0;
}