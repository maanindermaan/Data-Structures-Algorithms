// find first repeating element
#include<iostream>
#include<vector>
using namespace std;

void firstElement(vector<int>&arr){
    bool isRepeated = false;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i+1 ; j<arr.size() ; j++){
            if(arr[i]==arr[j]){
                cout<<"The first repeated element is at index : "<<i+1<<" and the element is : "<<arr[i]<<endl;
                isRepeated=true;
                break;
            }
        }
        if(isRepeated){
            break;
        }
    }
}

int main(){
    vector<int>arr{1,5,3,4,3,5,6};

    firstElement(arr);
return 0;
}