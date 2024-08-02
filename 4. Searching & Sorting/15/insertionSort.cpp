#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&arr){
    int n = arr.size();

    // Outer loop -> (n-1) rounds
    for(int round=1 ; round<n ; round++){
        // Step A -> Fetch
        int val = arr[round];
        int j;

        // Step B -> Compare : Compare jiss element pe khade ho usse pechle wale sabko compare kardo
        for(j=round-1 ; j>=0 ; j--){
            if(arr[j]>val){
                // Step C -> Shift
                arr[j+1] = arr[j];
            }
            else{
                // No shift
                break;
            }
        }

        // Step D -> Copy
        // because j nikalte hue subtract hogya hoga isliye j+1 kiya humne yha pe
        arr[j+1] = val;

    }
}

int main(){
    vector<int>arr{10,1,7,6,14,9};

    cout<<"Before Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
    insertionSort(arr);
    cout<<endl;
    cout<<"After Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}