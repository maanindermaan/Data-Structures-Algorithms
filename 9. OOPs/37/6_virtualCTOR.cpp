#include<iostream>
using namespace std;



class Base{
public:
    // virtual Base(){ not possible
    //     cout<<"base ctor"<<endl;
    // }
    ~Base(){
        cout<<"base dtor"<<endl;
    }
};



class Derived : public Base{
public:
    Derived(){
        cout<<"Derived ctor"<<endl;
    }
    ~Derived(){
        cout<<"Derived dtor"<<endl;
    }
};

int main(){
    Base *b = new Derived();
    delete b;
return 0;
}