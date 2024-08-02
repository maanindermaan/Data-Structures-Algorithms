#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int solve(vector<int>& piles , int i , int M , bool alice){
        if(i == piles.size()){
            return 0;
        }
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X = 1 ; X <= 2*M ; X++){
            if(i+X-1 >= piles.size()){
                break;
            }
            total += piles[i+X-1];
            // agar alice ki turn hai toh
            if(alice){
                ans = max(ans , (total + solve(piles , i+X , max(X , M) , !alice)));
            }
            // bob ki turn hai toh
            // 1. bob ne kitne stones pick kiye hai vo ni nikalna hume so no need to add total 
            // 2. bob ke case mein stones minimize karne honge because bob jab minimum dega vo minimum alice mein judega yha pe "total + solve(piles , i+X , max(X , M) , !alice)); " or mai chahta hu ki bob jo bhi de vo minimum ho taaki total mien judne ke baad minimum ho or mai ans ko select karu taaki ans maximum ho becuase i am doing max(ans , total+solve());(Alice ka ans MAXIMIZE HOGA)
            else{
                // ans = max(ans , total + solve(piles , i+X , max(X , M) , !alice));
                // 3. Ab agar mai ise MIN karrha hu toh ans ko initialse karna hoga maximum se
                ans = min(ans , 0 + solve(piles , i+X , max(X , M) , !alice));
            }
        }
        return ans;
    }

    int solveMemo(vector<int>& piles , int i , int M , bool alice , vector<vector<vector<int>>>&dp){
        if(i == piles.size()){
            return 0;
        }

        if(dp[i][M][alice] != -1){
            return dp[i][M][alice];
        }

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X = 1 ; X <= 2*M ; X++){
            if(i+X-1 >= piles.size()){
                break;
            }
            total += piles[i+X-1];
            // agar alice ki turn hai toh
            if(alice){
                ans = max(ans , total + solveMemo(piles , i+X , max(X , M) , !alice , dp));
            }
            // agar bob ki turn hai toh 
            else{
                ans = min(ans , 0 + solveMemo(piles , i+X , max(X , M) , !alice , dp));
            }
        }
        dp[i][M][alice] = ans;
        return dp[i][M][alice];
    }

    int solveTab(vector<int>&piles){

        vector<vector<vector<int>>>dp(piles.size()+1 , vector<vector<int>>(piles.size()+1 , vector<int>(2 , 0)));

        for(int i = piles.size()-1 ; i>=0 ; i--){
            for(int M = piles.size() ; M>=1 ; M--){
                for(int alice = 0 ; alice <=1 ; alice++ ){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;

                    for(int X = 1 ; X <= 2*M ; X++){
                        if(i+X-1 >= piles.size()){
                            break;
                        }
                        total += piles[i+X-1];
                        // agar alice ki turn hai toh
                        if(alice){
                            ans = max(ans , total + dp[i+X][max(X , M)][!alice]);
                        }
                        // agar bob ki turn hai toh 
                        else{
                            ans = min(ans , 0 + dp[i+X][max(X , M)][!alice]);
                        }
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }
        return dp[0][1][true];
    }

    int stoneGameII(vector<int>& piles) {
        // return solve(piles , 0 , 1 , true);

        // vector<vector<vector<int>>>dp(piles.size()+1 , vector<vector<int>>(piles.size()+1 , vector<int>(2 , -1)));
        // return solveMemo(piles , 0 , 1 , true , dp);

        return solveTab(piles);
    }
};