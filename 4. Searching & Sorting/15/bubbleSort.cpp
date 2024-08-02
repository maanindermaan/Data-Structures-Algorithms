#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();

    // Outer loop -> (n-1) rounds
    for(int round=1 ; round<n ; round++){
        bool swapped = false;
        for(int j=0 ; j<n-round ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1] , arr[j]);
                swapped=true;
            }
        }
        if(swapped == false){
            // Sort hochuka hai no need to check in futher rounds;
            break;
        }
    }
}

int main(){
    vector<int>arr{10,1,7,6,14,9};

    cout<<"Before Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr);
    cout<<endl;
    cout<<"After Sorting :"<<endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}