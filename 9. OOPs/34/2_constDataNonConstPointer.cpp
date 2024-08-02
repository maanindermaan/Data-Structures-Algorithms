#include<iostream>
using namespace std;
int main(){
    const int *a = new int(5); // CONST Data , NON-CONST Pointer
    //  int const *a = new int(5); // same as above

    // *a=10; // can't change the content of pointer 
    cout<< *a << endl;

    // Non CONST Pointer
    int b = 10;
    a = &b; // Pointer itself can be reassigned
    cout<< *a << endl;

return 0;
}