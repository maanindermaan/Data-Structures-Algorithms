// Same as Book allocation , Painters Partition and questinons like that DRY RUN PENDING 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    
    bool isPossible(vector<int>&arr , int N , int M , int sol){
        int pageSum = 0;
        int count = 1;

        for(int i=0 ; i<N ; i++){
            if(arr[i] > sol){
                return false;
            }
            else if(arr[i] + pageSum > sol){
                count++;
                pageSum = arr[i];
                if(count > M){
                    return false;
                }
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int start=0; 
        int end = accumulate(arr.begin() , arr.end() , 0);
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(arr , n , k , mid)){
                ans = mid;
                // search in left
                end = mid-1;
            }
            else{
                // search in right
                start = mid+1;
            }
        }
        return ans;
    }
};