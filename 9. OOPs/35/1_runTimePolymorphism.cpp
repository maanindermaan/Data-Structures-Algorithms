#include <iostream>
using namespace std;

class Animal{
        public:
        Animal() {
                cout << "i am inside animal constructor" << endl;
        }
        void speak() {
                cout << "Speaking " << endl;
        }
}; 

// class Animal{
//         public:
//         Animal() {
//                 cout << "i am inside animal constructor" << endl;
//         }
//         virtual void speak() {
//                 cout << "Speaking " << endl;
//         }
// };

class Dog: public Animal {
        public:
        Dog() {
                cout << "i am inside Dog constructor" << endl;
        }
        //override
         void speak() {
                cout << "barking" << endl; // agar yeah na hota to speaking print karte
        }
};

int main() {

        // Dog a;
        // a.speak();

        // Animal* a = new Animal();
        // a->speak();

        // Dog* a = new Dog();
        // a->speak();

        // UpCasting
        // Animal* a = new Dog();
        // a->speak(); // without virtual this gives speaking with virtual barking

        // //DownCasting
        // Dog* b = (Dog* )new Animal();
        // b->speak();

        // Constructor - Constructor
        // 1
        // Animal* a = new Animal(); // doesnot depends on anyone so only Animal Constructor

        // 2
        // Dog* a = new Dog(); // due to inheritaance both parent and child constructor will be called
    

        // 3
        // Animal* a = new Dog();// Actual mein vo right side pe depend karta hai so dog hai dono call hoga

        // 4
        // Dog* a = (Dog *)new Animal(); // Right mein animal jo ki parent hai to sirf parent constructor call hoyega



  return 0;
}