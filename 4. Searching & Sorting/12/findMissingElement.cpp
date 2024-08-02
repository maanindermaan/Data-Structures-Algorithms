#include<iostream>
using namespace std;

void findElement(int arr[] , int size){
    // calculating x
    int s = arr[0];
    int e = arr[size-1];
    int x = 0;

    for(int i=s ; i<=e ; i++){
        x += i;
    }

    // calculating y
    int y = 0;
    for(int i=0 ; i<size ; i++){
        y += arr[i];
    }

    cout<<x-y;
}

int main(){
    int arr[] = {1,2,3,4,6,7,8,9};
    int size = 8;
    findElement(arr , size);
return 0;
}