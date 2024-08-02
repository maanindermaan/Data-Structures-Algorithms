#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>&s , int &totalSize){
    // Base case
    if(s.size() == totalSize/2+1){
        cout<<"The middle element is : "<<s.top();
        return; // agar mil jaye to vaapis jao vrna segmentation fault aajega
    }

    // Ek case sambhal lo
    //Current element ko bhar nikalo
    int temp = s.top(); // temp ek local variable hai na mai use bhejrha hu har ek call ke bad vo recreate
    // hoga or na ki sirf recreate hoga, vo usi recursive column ke liye preserved bhi rhega.
    s.pop();

    // Recursive call
    printMiddle(s,totalSize);

    // BackTracking
    s.push(temp);
}

int main(){
    stack<int> s;

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);

        int totalSize = s.size();
        printMiddle(s,totalSize);

return 0;
}