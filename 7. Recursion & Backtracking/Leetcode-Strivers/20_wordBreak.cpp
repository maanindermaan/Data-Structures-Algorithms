#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main(){

return 0;
}


// 1. TLE
class Solution {
public:
    bool recursiveHelper(string str, vector<string>& wordDict, string part, int strIndex) {
        if (strIndex == str.size()) {
            return true;
        }

        for (int i = 0; i < wordDict.size(); i++) {
            for (int j = 1; j <= str.size() - strIndex; j++) { // Adjusted loop range to avoid out-of-bounds
                part += str.substr(strIndex, j);
                if (part == wordDict[i]) {
                    if (recursiveHelper(str, wordDict, "", strIndex + j)) {
                        return true;
                    }
                }
                part = ""; // Reset part after each iteration
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return recursiveHelper(s, wordDict, "", 0);
    }
};



// 2. Only set method but TLE again 
class Solution {
public:
    bool recursiveHelper(string str, unordered_set<string>& wordSet, string part, int strIndex) {
        if (strIndex == str.size()) {
            return true;
        }

        for (int j = 1; j <= str.size() - strIndex; j++) { 
            part += str.substr(strIndex, j);
            if( wordSet.find(part) != wordSet.end() && recursiveHelper(str, wordSet, "", strIndex + j )) {
                return true;
            }
            part = ""; 
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return recursiveHelper(s, wordSet, "", 0);
    }
};

// 3. Set and unordered map method
class Solution {
public:
    bool recursiveHelper(string str, unordered_set<string>& wordSet , unordered_map<int , bool>& map , int strIndex){
        if(strIndex == str.size()){
            return true;
        }

        if(map.find(strIndex) != map.end()){
            return map[strIndex];
        }

        for(int i=strIndex+1 ; i<=str.size() ; i++){
            if(wordSet.find(str.substr(strIndex , i-strIndex)) != wordSet.end() && recursiveHelper(str , wordSet , map , i)){
                return map[strIndex] = true;
            }
        }
        return map[strIndex] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin() , wordDict.end());
        unordered_map<int , bool>map;

        return recursiveHelper(s , wordSet , map , 0);
    }
};