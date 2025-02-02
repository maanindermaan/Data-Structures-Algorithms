#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>&ans , int open , int close , int n , string output){
    // Base Case
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }

    // Include Open Bracket
    if(open>0){
        output.push_back('(');
        // recursive call
        solve(ans , open-1 , close , n , output); // or output + '('if you dont want backtrack
        // backtrack
        output.pop_back();
    }
    // Include Close Bracket
    if(close>open){
        output.push_back(')');
        // recursive call
        solve(ans , open , close-1 , n , output);
        // backtrack
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";
    solve(ans , open , close , n , output);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of n :";
    cin>>n;
    vector<string> ans = generateParenthesis(n);
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<endl;
    }
return 0;
}














class Solution {
public:
    void solve(vector<string> &ans, int n,int used_open, int used_close, int rem_open, int rem_close, string output) {
        //base case 
        if(rem_open == 0 && rem_close == 0) {
            ans.push_back(output);
            return;
        }

        //include open bracket
        if(rem_open > 0 ){
            // output.push_back('(');
            solve(ans, n, used_open+1, used_close, rem_open-1, rem_close, output + '(' );
            //backtrack
            // output.pop_back();
        }

        //include close bracket
        if(used_open > used_close) {
            // output.push_back(')');
            solve(ans, n , used_open, used_close+1, rem_open, rem_close-1 ,output + ')');
            //backtrack
            // output.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int used_open = 0;
        int used_close = 0;
        int rem_open = n;
        int rem_close = n;
        string output = "";
        solve(ans, n, used_open, used_close, rem_open,rem_close, output);
        return ans;
    }
};