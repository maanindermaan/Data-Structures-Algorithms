#include<iostream>
using namespace std;

int partition(int arr[] , int s , int e){
    // step1: Pivot Choose  
    int pivotIndex = s;

    // step2: Find Right Pivot Poisition and place it there 
    int count = 0;
    for(int i=s+1 ; i<=e ; i++){
        if(arr[i] <= arr[pivotIndex]){
            count++;
        }
    }
    // jab main loop se bhar aaya toh mere paas pivot ka right index hai
    int rightIndex = count+s;
    swap(arr[pivotIndex] , arr[rightIndex]);
    pivotIndex = rightIndex; // updating value of pivot index

    // step3: left mein chote and right mein bade
    int i = s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }
        while(arr[j] > arr[pivotIndex]){
            j--;
        }

        // 2 cases may be seen here now
        // 1-> You found the element to swap;
        // 2-> No need to swap;
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i] , arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[] , int s , int e){
    // Base Case
    if(s>=e){
        return;
    }

    // Partition Logic
    int p = partition(arr , s , e);

    // Recursive Calls
    // Left
    quickSort(arr , s , p-1);

    // Right
    quickSort(arr , p+1 , e);

}

int main(){ 
    int arr[] = {8,3,4,1,20,50,30};
    int n=7;

    int s=0;
    int e=n-1;

    quickSort(arr , s , e);

    for(int i=0 ; i<n ; i++){
        cout<<arr[i] <<" ";
    }
return 0;
}