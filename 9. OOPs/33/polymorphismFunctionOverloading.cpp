// COMPILE TIME POLYMORPHISM
#include<iostream>
using namespace std;

class Maths{
    public:

    // FUNCTION OVERLOADING
    int sum(int a , int b){
        return a+b;
    }

    int sum(int a , int b , int c){
        return a+b+c;
    }

    int sum(int a , double b){
        return a+b;
    }
    // We can say that sum function is existing in multiple forms so there is polymorphism 
};

int main(){
    Maths obj;

    cout<<obj.sum(2,5); // 1st one called

    cout<<obj.sum(2,3,4); // 2nd one called

    cout<<obj.sum(2,5.12); // 3rd one called if you want to use float int this you have to write f at end eg 5.12f
return 0; 
}