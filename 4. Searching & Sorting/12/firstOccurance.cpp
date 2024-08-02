// Find the first occurance of the vector 
#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>arr , int target){
    int s = 0;
    int e = arr.size()-1;
    int mid = (s+e)/2;
    int index = -1;

    while(s<=e){
        if(arr[mid]==target){
            // ans store and move left
            index = mid;
            e = mid-1;
        }
        else if(target>arr[mid]){
            // right
            s = mid+1;
        }
        else{
            // left
            e = mid-1;
        }
        mid = (s+e)/2;
    }
    return index;
}

int main(){
    vector<int>arr{1,3,4,4,4,4,6,7};
    int target = 4;

    int ans = firstOccurance(arr,target);

    cout<<"The element "<<target<<" is present at "<<ans<<" index.";

    auto ans2 = lower_bound(arr.begin() , arr.end() , target);
    cout<<"The element "<<target<<" is present at "<<ans<<" index.";

return 0;
}