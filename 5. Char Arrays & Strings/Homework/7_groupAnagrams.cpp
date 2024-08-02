// #include<iostream>
// #include<map>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>&strs){
//     map<string , vector<string> >mp;

//     for(auto str : strs){
//         string s = str;
//         sort(s.begin() , s.end());
//         mp[s].push_back(str);
//     }
//     vector<vector<string>>ans;
//     for(auto it = mp.begin() ; it!=mp.end() ; it++){
//         ans.push_back(it->second);
//     } 

//     return ans;
// }

// int main(){
//     vector<string>strs {"eat" , "tea" , "tan" , "ate" , "nat" , "bat"};
//     vector<vector<string>>ans = groupAnagrams(strs);
    
//     // Print the anagram groups
//     for (int i = 0; i < ans.size(); i++) {
//         for (int j = 0; j < ans[i].size(); j++) {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
// return 0;
// }



























// METHOD - 1
// #include <iostream>
// #include <map>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     map<string, vector<string>> mp;

//     for (int i = 0; i < strs.size(); i++) {
//         string s = strs[i];
//         sort(s.begin(), s.end());
//         mp[s].push_back(strs[i]);
//     }
    
//     vector<vector<string>> ans;
//     for (auto it = mp.begin(); it != mp.end(); it++) {
//         ans.push_back(it->second);
//     }

//     return ans;
// }

// int main() {
//     vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
//     vector<vector<string>> ans = groupAnagrams(strs);

//     // Print the anagram groups
//     for (int i = 0; i < ans.size(); i++) {
//         for (int j = 0; j < ans[i].size(); j++) {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }























// METHOD-2
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

std::array<int, 256> calculateHash(string s) {  // function
    std::array<int, 256> hash = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<std::array<int, 256>, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[calculateHash(s)].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->second);
    }

    return ans;
}

int main() {
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    // Print the anagram groups
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}





// Inefficient My way - 3
class Solution {
public:

    bool isAnagram(string s , string t){
        int frequencyTable[256] = {0};

        if(s.size() != t.size()){
            return false;
        }

        for(int i=0 ; i<s.size() ; i++){
            frequencyTable[s[i]]++;
        } 
        for(int i=0 ; i<t.size() ; i++){
            frequencyTable[t[i]]--;
        }
        for(int i=0 ; i<256 ; i++){
            if(frequencyTable[i] != 0 ){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {


        unordered_map<string , int>map;
        vector<vector<string>>finalAns;
        vector<string>ans;

        for(int i=0 ; i<strs.size() ; i++){
            map[strs[i]] = 0;
        }
        for(int i=0 ; i<strs.size() ; i++){
            ans.clear();
            for(int j=0 ; j<strs.size() ; j++){
                if(i != j && isAnagram(strs[i] , strs[j])){
                    if(map[strs[i]] == 0){
                        ans.push_back(strs[i]);
                        map[strs[i]]++;
                    }
                    if(map[strs[j]] == 0){
                        ans.push_back(strs[j]);
                        map[strs[j]]++;
                    }
                }
                // if(i != j && strs[i] == "" && cnt > 0){
                //     ans.push_back(strs[i]);
                //     cnt--;
                // }
            }
            if(map[strs[i]] == 0){
                ans.push_back(strs[i]);
                map[strs[i]]++;
            }
            if(!ans.empty()){
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }
};



// Some Better Solution - 4
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>map;
        vector<vector<string>>finalAns;

        for(auto s : strs){
            string sorted = s;
            sort(sorted.begin() , sorted.end());
            map[sorted].push_back(s);
        }

        for(auto i : map){
            finalAns.push_back(i.second);
        }

        return finalAns;
    }
};