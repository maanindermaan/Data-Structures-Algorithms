// BASIC INHERITANCE
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//            int age;
//            int weight; 

//            void eat(){
//             cout<<"Eating";
//            }
//  };

// //  Syntax of child Class
//  class Dog:public Animal{

//  };

// int main(){
//     Dog d;
//     d.eat();
//     cout<<endl;
//     cout<<d.age;

// return 0;
// }






// MODE OF INHERITANCE
// A) PUBLIC
// 1) Public -> mode of inheritance (public) -> Public
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//         int age;
//         int weight; 
//  };

// //  Child Class
//  class Dog:public Animal{

//  };

// int main(){
//     Dog d1;
//     d1.age = 10;
//     cout<<d1.age; 
// return 0;
// }



// // 2) Public -> mode of inheritance (protected) -> Protected -> Can not be acccessed like that we have to create a function inside
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//         int age;
//         int weight;         
//  };

// //  Child Class
//  class Dog:protected Animal{
//     void ageD1(){
//         cout<<age;
//     }
//  };

// int main(){
//     Dog d1;
//     // d1.age = 10;
//     // cout<<d1.age; 
// return 0;
// }




// // 2) Public -> mode of inheritance (protected) -> Protected -> Can not be acccessed like that we have to create a function inside
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:protected Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }




// 3) Public -> mode of inheritance (private) -> Private -> Can not be acccessed like that we have to create a function inside
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:private Animal{
//     public:
//     void print(){
//         cout<<age;
//     }
//  };

// int main(){
//     Dog d1;
//     // d1.age = 10;
//     // cout<<d1.age; 
//     d1.print();
// return 0;
// }





// 3) Public -> mode of inheritance (private) -> Private -> Can not be acccessed like that we have to create a function inside
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     public:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:private Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }





// B) PROTECTED
// 1) Protected-> mode of inheritance(public) -> Protected -> Acceseed inside child class only
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     protected:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:public Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }




// 2) Protected-> mode of inheritance(protected) -> Protected -> Acceseed inside child class only
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     protected:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:protected Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }




// 3) Protected-> mode of inheritance(private) -> Private -> Acceseed inside child class only
// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     protected:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:private Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }




// C) PRIVATE
// PRIVATE -> Any mode of inheritance -> N/A

// #include<iostream>
// using namespace std;

// // Parent Class
//  class Animal{
//     private:
//            int age;
//            int weight; 
//  };

// //  Child Class
//  class Dog:private Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
//  };

// int main(){
//     Dog d1;
//     d1.print();
// return 0;
// }