#include<iostream>
using namespace std;
int main(){
    int *a = new int;
    *a=2;
    cout<< *a << endl;
    delete a; // Helps to prevent memeory leak

    int b = 5;
    a = &b; // we should delete a before assigning to other variables
    cout<< *a << endl;
return 0;
}