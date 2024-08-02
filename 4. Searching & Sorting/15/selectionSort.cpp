#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr){
    int n = arr.size();

    // Outer loop -> (n-1) rounds
    for(int i=0 ; i<n-1 ; i++){ // outer loop for i = 0 , i = 1 and so on for iterations / rounds / passes |||| last element to already sorted hoga so we use loop till n-1 index
        int minIndex = i;
        // Index of min element from i->n
        for(int j=i+1 ; j<n ; j++){ // comparison next element se shuru hoga or last element tak hoga
            if(arr[j]<arr[minIndex]){
                // New minimum then store it 
                minIndex = j;
            }
        }
        swap(arr[i] , arr[minIndex]);
    }
}

int main(){
    vector<int>arr{8,9,10,12,5,4,14,2};

    cout<<"Before Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
    selectionSort(arr);
    cout<<endl;
    cout<<"After Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}