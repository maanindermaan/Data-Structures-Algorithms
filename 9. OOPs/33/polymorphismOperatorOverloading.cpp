#include<iostream>
using namespace std;

class Param{
    public:
    int val;

    void operator - (Param &obj2){
        int value1 = this->val; // it is a pointer to current object i.e. it is a pointer to obj1. obj1->val = 10
        int value2 = obj2.val; // we can access 5 this way

        cout<<(value1 - value2)<<endl;
    }
};

int main(){
    Param obj1 , obj2;
    obj1.val = 10;
    obj2.val = 5;

    // this should return difference not sum;
    obj1 - obj2;  // + operator se - hona chiye. Also 'obj1' is curr object. '+' is member function and 'obj2' is i/p paramter

return 0;
}