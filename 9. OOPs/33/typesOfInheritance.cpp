#include<iostream>
using namespace std;

// 1. SINGLE LEVEL INHERITANCE
// class Car{
//     public:
//     int age;
//     int weight;

//     void speedUp(){
//         cout<<"Speeding up"<<endl;
//     }

//     void breaks(){
//         cout<<"Breaking down"<<endl;
//     }
// };

// class Fortuner:public Car{ // FORTUNER is a CAR (here is a is inheritance (RELATIONSHIP)) 

// };

// int main(){
//     Fortuner f1;
//     cout<<f1.age;
//     cout<<f1.weight; 
//     f1.speedUp();
//     f1.breaks();
// return 0;
// }



// 2. MULTILEVEL
// #include<iostream>
// using namespace std;

// class Fruit{
//     public:
//     int weight = 5;
// };

// class Mango : public Fruit{
//     public:
//     int age = 10;
// };

// class Alphanso : public Mango{
//     public:
//     int sugarLevel = 15;
// };

// int main(){
//     Alphanso a;
//     a.weight;
//     a.age;
//     a.sugarLevel;
// return 0;
// }




// 3. MULTIPLE
// #include<iostream>
// using namespace std;

// class A{
//     public:
//     int physics;
// };

// class B{
//     public:
//     int chemistry;
// };

// class C : public A, public B{
//     public:
//     int biology;
// };

// int main(){
//     C c;
//     c.physics;
//     c.biology;
//     c.chemistry;
// return 0;
// }



// DIAMOND PROBLEM
// #include<iostream>
// using namespace std;

// class A{
//     public:
//     int chemistry;
//     A(){
//         chemistry = 101;
//     }
// };

// class B{
//     public:
//     int chemistry;
//     B(){
//         chemistry = 202;
//     }
// };

// class C : public A, public B{
//     public:
//     int biology;
// };

// int main(){
//     C c;
//     cout<<c.biology<<endl;
//     cout<<c.A::chemistry<<endl;
//     cout<<c.B::chemistry<<endl;
// return 0;
// }




// 4. HEIRARICAL
#include<iostream>
using namespace std;

class Car{
    public:
    int age;
    int weight;
    string name; 

    void speedUp(){
        cout<<"Speeding Up"<<endl;
    }
};

class Scorpio : public Car{

};

class Fortuner : public Car{

};  


int main(){
    Scorpio s11; Fortuner f11;
    s11.speedUp();
    f11.speedUp();
return 0;
}





