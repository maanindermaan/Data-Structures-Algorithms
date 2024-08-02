#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int *y;
    abc(int _x , int _y) : x(_x) , y(new int(_y)){
        cout<<"INITIALIZED"<<endl;
    }

    // Default dumb copy constructor : it does SHALLOW COPY. 
    // Jo a ke andar pointer tha y vohi isne b ke andar call krdiya 
    // abc(const abc &obj){
    //     x = obj.x; 
    //     y = obj.y;
    // }

    // SMART DEEP COPY
    // abc(const abc &obj){
    //     x = obj.x; 
    //     y = new int(*obj.y);
    // }

    void print(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<*y<<endl;
    }

    // ONE MORE PROBLEM OF SHALLOW COPY
    ~abc(){
        delete y;
    }
};

int main(){
    abc a(1,2);
    cout<<"Printing a:"<<endl;
    a.print();

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;

    abc b = a; // these a and b pointing to same location // COPY CONSTRUCTOR
    cout<<"Printing b:"<<endl;
    b.print(); 

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;


    *b.y = 20; // changing value in obj b
    cout<<"Printing b:"<<endl;
    b.print(); 

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;


    cout<<"Printing a:"<<endl;
    a.print(); // chaninging b changes a as well this is a bIG SECURITY FLOW
















    // ONE MORE PROBLEM OF SHALLOW COPY -> MALLOC DOUBLE FREE OF OBJECTS
    // abc *a = new abc(1,2);
    // abc b = *a;
    // delete a;
    // b.print();

return 0;
}