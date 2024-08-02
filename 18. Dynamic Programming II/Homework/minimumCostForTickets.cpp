#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:

    int minCostUsingRecursion(vector<int>& days, vector<int>& costs , int i){
        // base case
        if(i >= days.size()){
            return 0;
        }

        // solution for 1 case
        // 1 days pass
        int cost1 = costs[0] + minCostUsingRecursion(days , costs , i+1);

        // 7 day pass
        int passEndDay = days[i] + 7-1;
        int j = i;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost7 = costs[1] + minCostUsingRecursion(days , costs , j);

        // 30 day pass
        passEndDay = days[i] + 30-1;
        j = i;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost30 = costs[2] + minCostUsingRecursion(days , costs , j);

        // also j will point to next index like if there are 3 elements in array and j traverse over whole array then at end j will have a value 0 1 2 and now j = 3 after loop ends

        return min(cost1 , min(cost7 , cost30));
    }


    int minCostUsingMemo(vector<int>& days, vector<int>& costs , int i , vector<int>&dp){
        // base case
        if(i >= days.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // solution for 1 case
        // 1 days pass
        int cost1 = costs[0] + minCostUsingMemo(days , costs , i+1 , dp);

        // 7 day pass
        int passEndDay = days[i] + 7-1;
        int j = i;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost7 = costs[1] + minCostUsingMemo(days , costs , j , dp);

        // 30 day pass
        passEndDay = days[i] + 30-1;
        j = i;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost30 = costs[2] + minCostUsingMemo(days , costs , j , dp);

        // also j will point to next index like if there are 3 elements in array and j traverse over whole array then at end j will have a value 0 1 2 and now j = 3 after loop ends

        dp[i] = min(cost1 , min(cost7 , cost30));

        return dp[i];
    }

    int minCostUsingTab(vector<int>& days, vector<int>& costs , int i){

        vector<int>dp(days.size()+1 , 0);

        // dp[days.size()] = 0;
        
        for(int index = days.size()-1 ; index>=0 ; index--){ // replace i -> index
            int cost1 = costs[0] + dp[index+1];

        // 7 day pass
        int passEndDay = days[index] + 7-1;
        int j = index;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost7 = costs[1] + dp[j];

        // 30 day pass
        passEndDay = days[index] + 30-1;
        j = index;

        while(j<days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost30 = costs[2] + dp[j];

        dp[index] = min(cost1 , min(cost7 , cost30));

        }
        return dp[i];
    }




    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return minCostUsingRecursion(days , costs , 0);

        // vector<int>dp(days.size()+1 , -1);
        // return minCostUsingMemo(days , costs , 0 , dp);

        return minCostUsingTab(days , costs , 0);
    }
};