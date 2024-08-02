#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    bool isPossible(vector<int>& arr , int m , int k , int minDays){
        int cnt = 0;
        int noOfBouq = 0;
        cout<<minDays<<endl;
        for(int i=0 ; i<arr.size(); i++){
            if(arr[i] <= minDays){
                cnt++;
            }
            else{
                noOfBouq += cnt/k;
                cnt = 0;
            }
        }
        noOfBouq += cnt/k;
        if(noOfBouq >= m){
            return true;
        }
        else{
            return false;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin() , bloomDay.end());;
        int end = *max_element(bloomDay.begin() , bloomDay.end());
        int ans = end;

        long long val = m * 1LL * k * 1LL;

        // base case
        if(val > bloomDay.size()){
            return -1;
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            if(isPossible(bloomDay , m , k , mid)){
                // store and move left for minimum
                ans = mid;
                end = mid-1;
            }
            else{
                // else move right
                start = mid+1;
            }
        }
        return ans;
    }
};