#include<iostream>
using namespace std;

// By this way we have encapsulated our data memebers and member functions into class
 class Animal{
    public:
           int age;
           int weight; 

           void eat(){
            cout<<"Eating";
           }
 };

//  PREFECT ENCAPSULATION -> to access private members we use getters and setters;
 class Animal{
    private:
           int age;
           int weight; 
    public:       
           void eat(){
            cout<<"Eating";
           }
           int getAge(){
            return this->age;
           }
           void setAge(int age){
            this->age = age;
           }
 };

int main(){

return 0;
}