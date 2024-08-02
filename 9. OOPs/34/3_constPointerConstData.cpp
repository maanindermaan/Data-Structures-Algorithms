#include<iostream>
using namespace std;
int main(){
    const int *const a = new int(10);
    cout<<*a<<endl;
    // *a = 20; //error CONST DATA


    int b =77;
    // a = &b; // error CONST PTR
return 0;
}