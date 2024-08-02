// #include<iostream>
// using namespace std;

// class A{
//     private:
//     int x;
//     public:
//     A(int _val):x(_val){};

//     int getter() const{ // isko const karne se im assuring a down ki iski value mein koi change ni hoga
//         // x=2; // cant change due to const
//         return x;
//     }
//     void setter(int _val){
//         x = _val;
//     }
// };

// class B{
//     public:
//     void print(const A &a){
//         cout<<a.getter()<<endl;  // a ka data member ni change ho sakta due to cons. TO mujhe gettter ko bhi const karna padgea
//     }
// };

// int main(){
//     A a(5);
//     B b;
//     b.print(a);
// return 0;
// }




// AGAR MAI CHAHTA HU KI CLASS B CLASS A ke pvt members ko acces kar sakte without getter and setter then? 
// WE use friend function.
// A or B ko friend banao.
// agar B A ka friend hai to B ko saare PVT. mmebers ka access dedo
#include<iostream>
using namespace std;

class A{
    private:
    int x;
    public:
    A(int _val):x(_val){};

    friend class B;
    friend void print(const A&);
};

class B{
    public:
    void print(const A &a){
        cout<<a.x<<endl;  // possible due to line 50
    }
};

void print(const A &a){ // Friend Function
    cout<<a.x<<endl;  // possible due to line 51
}

int main(){
    A a(5);
    B b;
    b.print(a);
    print(a);
return 0;
}