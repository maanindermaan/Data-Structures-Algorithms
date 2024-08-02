#include<iostream>
using namespace std;

void printArray(int arr[] , int n , int i){
    // Base Case
    if(i>=n){
        return;
    }

    // 1 case maine solve krdiya
    cout<<arr[i]<<" ";

    // Baaki recursion ne sambhal liya
    printArray(arr , n , i+1);
    
}

void print(int arr[] , int n , int i){
    // Base Case
    if (i>=n){
        return;
    }
    print(arr , n , i+1);

    cout<<arr[i]<<"->";

    
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int i = 0;

    print(arr , n , i);
return 0;
}