#include<iostream>
using namespace std;

void printPermutation(string& str , int i){
    // Base Case
    if(i>=str.size()){
        cout<<str<<" ";
        return;
    }

    // Swapping
    for(int j=i; j<str.length() ; j++){
        // swap
        swap(str[i] , str[j]);
        // recursive call
        printPermutation(str , i+1);
        // Backtracking - To recreate the orignal input
        swap(str[i] , str[j]);
    }
}

int main(){
    string str = "abc";
    int i=0; 

    printPermutation(str , i);
return 0;
}