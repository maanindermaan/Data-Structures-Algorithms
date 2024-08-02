// Method 1
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    static bool mycomp(pair<char , int>a , pair<char , int>b){
        return a.second > b.second;
    }

    string frequencySort(string s) {

        vector<pair<char , int>>arr;
        string ans = "";

        for(auto ch : s){
            bool found = false;
            for(auto& i : arr){
                // element hai to increment krdo
                if(i.first == ch){
                    i.second++;
                    found = true;
                    break;
                }
            }
            // agar koi element nahi hai toh use daldo
            if(found == false){
                arr.push_back({ch , 1});
            }
        }
    
        sort(arr.begin() , arr.end() , mycomp);

        for(auto i : arr){
            while(i.second--){
                ans+=i.first;
            }
        }
        return ans;
    }
};




// Method 2
class Solution {
public:
    static bool mycomp(pair<char , int>a , pair<char , int>b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char , int>freqMap;
        vector<pair<char , int>>freqVec;
        string ans = "";

        // using map
        for(char i : s){
            freqMap[i]++;
        }

        // pushing to vector
        for(auto ch : freqMap){
            freqVec.push_back(ch);
        }
    
        sort(freqVec.begin() , freqVec.end() , mycomp);

        // constructing string 
        for(auto i : freqVec){
            ans += string(i.second , i.first);
        }

        return ans;
    }
};