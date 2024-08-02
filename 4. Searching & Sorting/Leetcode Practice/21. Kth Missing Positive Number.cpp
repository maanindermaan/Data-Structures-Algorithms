#include<iostream>
#include<vector>

using namespace std;
int main(){

return 0;
}
// Not that much Optimised -1
class Solution {
public:

    int binarySearch(vector<int>&arr , int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = (start + end)/2;

    while(start<=end){

        if(target == arr[mid]){
            // Element found
            return mid;
        }
        else if(target<arr[mid]){
            // Search in left
            end = mid-1;
        }
        else{
            //Search in right
            start = mid+1;
        }

        //calculate mid again because mid will be updated due to above two elseif and else loops
        mid = (start+end)/2;
    }

    // Element not found
    return -1;
}

    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int count = 0;

        while(count <= k){
            if(binarySearch(arr , i) != -1){
                i++;
            }
            else{
                count++;
                if(count == k){
                    break;
                }
                i++;
            }
        }
        return i;
    }
};


// Brute force -2 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] <= k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
    }
};



// Optimised Answer
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size()-1;

        while(start <= end){
            int mid = start + (end-start)/2;
            int missing = arr[mid] - (mid+1);

            if(missing < k){
                // eliminate left half 
                start = mid+1;
            }
            else{
                // eliminate right half
                end = mid-1;
            }
        }
        // at end you get high at desrired position
        return k+end+1;
        // all explanantion in notebook
    }
};