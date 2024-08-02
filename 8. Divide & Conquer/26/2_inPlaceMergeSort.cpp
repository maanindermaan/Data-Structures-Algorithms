#include<iostream>
using namespace std;

void mergeTwoSortedArrays(int* arr , int s , int mid , int e){

    int* temp = new int[e - s + 1]; // Temporary array to store merged elements

    int leftIndex = s; // Index for the left subarray
    int rightIndex = mid + 1; // Index for the right subarray
    int tempIndex = 0; // Index for the temporary array

    while (leftIndex <= mid && rightIndex <= e) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            temp[tempIndex++] = arr[leftIndex++];
        } else {
            temp[tempIndex++] = arr[rightIndex++];
        }
    }

    // Copy the remaining elements from the left subarray
    while (leftIndex <= mid) {
        temp[tempIndex++] = arr[leftIndex++];
    }

    // Copy the remaining elements from the right subarray
    while (rightIndex <= e) {
        temp[tempIndex++] = arr[rightIndex++];
    }

    // Copy the merged elements back to the original array
    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }

    delete[] temp; // Free the temporary array
}

void mergeSort(int* arr , int s , int e){
    if (s >= e) {
        return; // Base case: single element or invalid array
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid); // Sort the left half
    mergeSort(arr, mid + 1, e); // Sort the right half

    mergeTwoSortedArrays(arr, s, mid, e); // Merge the sorted halves
}

int main(){
    int arr[] = {3,9,20,27,38,43};
    int n = 6;
    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e); // Calling merge sort function

    // Printing the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
