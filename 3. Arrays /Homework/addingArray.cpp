// Adding the elements of two arrays and then storing them into another array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sum(int arr1[] , int arr2[] , int size1 , int size2){
    vector<int>arr;
    int carry=0;
    int i = size1-1;
    int j = size2-1;

    // When arr1 and arr2 have equal elements
    while(i>=0 && j>=0){
        int x = arr1[i]+arr2[j]+carry;
        int digit = x%10;
        carry=x/10;
        arr.push_back(digit);
        i--;
        j--;
    }

    // When arr2 is over but arr1 is left
    while(i>=0){
        int x = arr1[i]+0+carry;
        int digit = x%10;
        carry=x/10;
        arr.push_back(digit);
        i--;
    }

    // When arr1 is over but arr2 is left
    while(j>=0){
        int x = 0+arr2[j]+carry;
        int digit = x%10;
        carry=x/10;
        arr.push_back(digit);
        j--;
    }

    // Carry bacha hua hoto use bhi daldo
    if(carry){
        arr.push_back(carry);
    }

    reverse(arr.begin() , arr.end());

    for(int i=0 ; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr1[] = {9,0,0,3,5};
    int arr2[] = {2,2,7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    sum(arr1 , arr2 , size1 , size2);
return 0;
}