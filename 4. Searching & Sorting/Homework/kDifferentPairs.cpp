// METHOD - 1 -> TWO POINTERS APPROACH
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int kDifferentPairs(int arr[] , int size , int k){
    
    sort(arr , arr+size);
    int i=0 , j=1;
    // int ans = 0; Cannot have distinct values can copy same values eg 1 1 1 1 1

    set<pair<int, int>> ans;

    while(j<size){
        int diff = arr[j] - arr[i];
        
        if(diff == k){
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            ans.insert({arr[i] , arr[j]});
            i++;
            j++;
        }

        else if(diff>k){
            i++;
        }

        else{
            j++;
        }

        // Hume nahi chahihye i!=j hume same number ko minus nahi karna
        if(i==j){
            j++;
        }
    }
    return ans.size();

}

int main(){
    int arr[] = {3,1,4,1,5};
    int size = sizeof(arr)/sizeof(arr[888]);
    int k;
    cout<<"Enter the value of k : ";
    cin>>k;
    int ans = kDifferentPairs(arr , size , k);
    // kDifferentPairs(arr , size , k);

    cout<<ans;
return 0;
}





// METHOD - 2 -> BINARY SEARCH APPROACH
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int binarySearch(vector<int>&arr , int s , int x){
    int e = arr.size() - 1;

    while(s<=e){
        int mid = s + (e-s)/2;
        
        if(arr[mid] == x){
            return mid;
        }

        else if(x>arr[mid]){
            // Right Side
            s = mid+1;
        }

        else{
            // Left Side
            e = mid-1;
        }
    }
    return -1;
}  

int kDifferentPairs(vector<int>&arr , int k){
    sort(arr.begin() , arr.end());
    set<pair<int , int>>ans;

    for(int i=0 ; i<arr.size() ; i++){
        if(binarySearch(arr , i+1 , arr[i] + k)!=-1){
            ans.insert({arr[i] , arr[i]+k});
        }
    }

    return ans.size();
}

int main(){
    vector<int>arr{3,1,4,1,5};

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    int ans = kDifferentPairs(arr , k);

    cout<<ans;

return 0;
}



// Method 3 -> correct method
class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        // 1. sort 
        sort(arr.begin() , arr.end());
        
        // 2. Take two pointers 
        int i = 0;
        int j = 1;
        set<pair<int, int>> ans;

        while(j<arr.size()){
            if((arr[j] - arr[i]) == k && i!=j){
                ans.insert({arr[i] , arr[j]});
                i++;
                j++;
            }
            else if((arr[j] - arr[i]) > k){
                // move i forward
                i++;
            }
            else{
                j++;
            }
        }
        return ans.size();
    }
};