#include<iostream>
using namespace std;

void mergeTwoSortedArrays(int* arr , int s , int e){

    int mid = s + (e-s)/2;

    int len1 = (mid-s)+1;
    int len2 = e-mid;

    // assume to create array for lenth len1 and len2
    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = s;
    for(int i=0 ; i<len1 ; i++){
        left[i] = arr[k];
        k++;
    }
    // Other method to copy values
    // int i=0;
    // while(i<len1){
    //     left[i++] = arr[k++];
    // }

    k=mid+1;
    for(int i=0 ; i<len1 ; i++){
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // agar koi array jaldi end hogya toh!!
    // for left
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // for right
    while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // TODO : can be used to delete newly constructed array
}

void mergeSort(int* arr , int s , int e){
    // Base Case
    // s==e -> single element
    // s>e -> invalid array
    if(s>=e){
        return;
    }

    int mid = s+(e-s)/2;

    // Left case solve krdo recursion
    mergeSort(arr,s,mid);

    // right case solve krdo recursion
    mergeSort(arr,mid+1,e);

    // merge 2 sorted arrays
    mergeTwoSortedArrays(arr , s , e);
}

int main(){
    int arr[] = {3,9,20,27,38,43};
    int n = 6;
    int s = 0;
    int e = n-1;

    // Calling merge sort function
    mergeSort(arr , s , e);

    // printing the array 
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}







