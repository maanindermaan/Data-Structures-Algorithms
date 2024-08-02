#include<iostream>
#include<map>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    #define INF (1e9 + 1)

    int solve(vector<int>& arr1, vector<int>& arr2 , int prev , int i){
        // base case
        if(i == arr1.size()){
            return 0;
        }

        int opt1 = INF;
        if(prev < arr1[i]){
            // 1. to simply aage bad jao
            opt1 = solve(arr1 , arr2 , arr1[i] , i+1);
        }

        // 2. Aise hi aankh band krke aage mat bado pehle check kro
        int opt2 = INF;
        // finding just bada element using upper bound
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        // ab iss just bade element ka index find out karlo agar ye milgya hai toh
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // ab niche wali line ye problem aayegi ki orignal array arr1 modify hogai or aage possibilities find krne mein kregi problem, because mai dusri possibility mein orignal array bhejunga
            // arr1[i] = arr2[index];
            // opt2 = 1 + solve(arr1 , arr2 , arr1[i] , i+1);
            opt2 = 1 + solve(arr1 , arr2 , arr2[index] , i+1);
        }
        return min(opt1 , opt2);
    }


    int solveMemo(vector<int>& arr1, vector<int>& arr2 , int prev , int i , map<pair<int , int> , int>&dp){
        if(i == arr1.size()){
            return 0;
        }
        if(dp.find({prev , i}) != dp.end()){// milgaya
            return dp[{prev , i}];
        }

        int opt1 = INF;
        if(prev < arr1[i]){
            opt1 = solveMemo(arr1 , arr2 , arr1[i] , i+1 , dp);
        }

        int opt2 = INF;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            opt2 = 1 + solveMemo(arr1 , arr2 , arr2[index] , i+1 , dp);
        }
        dp[{prev , i}] = min(opt1 , opt2);
        return dp[{prev , i}];
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // sort aar2 first
        sort(arr2.begin() , arr2.end());
        // hum prev ki value lenge or curr ka index lenge
        // int ans = solve(arr1 , arr2 , -1 , 0);   

        // 2 values change hori hai toh map of pair banalo
        map<pair<int , int> , int>dp;  // {prev , i} = {ans};
        int ans = solveMemo(arr1 , arr2 , -1 , 0 , dp);
        return ans == INF ? -1 : ans;
    }
};