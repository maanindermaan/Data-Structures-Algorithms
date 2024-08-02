#include<iostream>
#include<limits.h>
using namespace std;

void maxElement(int arr[] , int n , int i , int& maxi){
    // Base Case
    if(i>=n){
        return;
    }

    // 1 case maine solve krdiya
    if(arr[i]>maxi){
        maxi = arr[i];
    }

    // Baaki recursion ne sambhal liya
    maxElement(arr , n , i+1 , maxi);
}


void minElement(int arr[] , int n , int i , int& mini){
    // Base Case
    if(i>=n){
        return;
    }

    // 1 case maine solve krdiya
    if(arr[i]<mini){
        mini = arr[i];
    }

    // Baaki recursion ne sambhal liya
    minElement(arr , n , i+1 , mini);
}

void maxm(int arr[] , int n , int i , int& maxi){
    if(i>=n){
        return;
    }

    if(arr[i] > maxi){
        maxi = arr[i];
    }

    maxm(arr , n , i+1 , maxi);

}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int i = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    maxm(arr , n , i , maxi);
    minElement(arr , n , i , mini);
    cout<<maxi<<endl;
    cout<<mini;
return 0;
}