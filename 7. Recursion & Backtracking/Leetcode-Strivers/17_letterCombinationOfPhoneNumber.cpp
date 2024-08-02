#include<iostream>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
public:
    unordered_map<char, vector<char>> mp {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };


    void recursiveHelper(string& digits , vector<string>&ans , string& part , int index){
        // base case
        if(index == digits.size()){
            ans.push_back(part);
            return;
        }

        for(auto it : mp[digits[index]]){
            part.push_back(it);
            recursiveHelper(digits , ans , part , index+1);
            part.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string part;

        if(digits.empty()){
            return ans;
        }

        recursiveHelper(digits , ans , part , 0);

        return ans;
    }
};

// 2.
class Solution {
public:
    unordered_map<char, string> mp {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };


    void recursiveHelper(string& digits , vector<string>&ans , string& part , int index){
        // base case
        if(index == digits.size()){
            ans.push_back(part);
            return;
        }

        for(auto it : mp[digits[index]]){
            part.push_back(it);
            recursiveHelper(digits , ans , part , index+1);
            part.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string part;

        if(digits.empty()){
            return ans;
        }

        recursiveHelper(digits , ans , part , 0);

        return ans;
    }
};