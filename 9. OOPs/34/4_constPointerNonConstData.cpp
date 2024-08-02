#include<iostream>
using namespace std;
int main(){
    int *const a = new int(10);
    cout<<*a<<endl;
    *a = 20; // chal jayega NON-CONST data
    cout<<*a<<endl;

    int b =77;
    // a = &b; // nahi chalega CONST POINTER
return 0;
}