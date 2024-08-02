#include<iostream>
using namespace std;

class abc{
    public:
    static int x , y;

    static void print(){ // No ''this'' pointer available
        cout<<x<<" "<<y<<endl;
    }
};

// Initialising static data memebrs. x and  ki ek hi copy hai har ek object ya instance ke liye
int abc::x;
int abc::y;

int main(){
    // abc obj1;
    // obj1.x = 1;
    // obj1.y = 2;
    // obj1.print();

    // abc obj2;
    // obj2.x = 10;
    // obj2.y = 20;
    // obj2.print();
    // obj1.print(); // becuase ek hi x , y hai update krdiye obj2 ne to isliye same aarha hai 


    //  Ab yeah jo print function hai ye saare instances mein common hoga, kisi bhi particular instance ka 
    // Nahi hoga to hum isko aise bhi likh sakte hai

    abc obj1;
    abc::x = 1;
    abc::y = 2;
    abc::print();

    abc obj2;
    abc::x = 10;
    abc::y = 20;
    abc::print();
    abc::print(); 
    
return 0;
}