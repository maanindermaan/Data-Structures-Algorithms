#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>& ans , string digits , int index , string output , vector<string>& mapping){
    // Base Case
    if(index >= digits.size()){
        ans.push_back(output);
        return;
    }

    // 1 case solve, baaki recursion 
    int digit = digits[index] - '0' ; // coverting char to int
    string value = mapping[digit];
    for(int i=0 ; i<value.size() ; i++){
        char ch = value[i];
        output.push_back(ch);
        // Recursive call
        solve(ans , digits , index+1 , output , mapping);
        // backtracking
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits){

    vector<string> ans;
    
    // Empty string
    if(digits.length() == 0){
        return ans;
    }
    int index =0 ;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(ans , digits , index , output , mapping);
    return ans;
}

int main(){
    string digits;
    cout<<"Enter the value of digits :";
    cin>>digits;
    vector<string> ans = letterCombinations(digits);
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<endl;
    }
return 0;
}