#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// Method - 2
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

// // Method - 1
// bool isAnagram(string s , string t){
//     sort(s.begin() , s.end());
//     sort(t.begin() , t.end());

//     if(s.size() != t.size()){
//         return false;
//     }

//     for(int i=0 ; i<=s.size() ; i++){
//         if(s[i] == t[i]){
//             return true;
//         }
//     } 
//     return false;
// }

// Method 1 updated only
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin() , s.end());
//         sort(t.begin() , t.end());

//         if(s.compare(t) == 0){
//             return true;
//         }
//         return false;
//     }
// };


int main(){
    string s = "anagram";
    string t = "margana";

    bool ans = isAnagram(s , t);
    if(ans){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
return 0;
}



// 3. Sort Approach
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        if(s.find(t)!=string::npos){
            return true;
        }

        return false;
    }
};





// 4. Map Approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char , int>string1;
        unordered_map<char , int>string2;

        for(int i=0 ; i<s.length() ; i++){
            string1[s[i]]++;
        }

        for(int i=0 ; i<t.length() ; i++){
            string2[t[i]]++;
        }

        for(auto i:string1){

            auto it = string2.find(i.first);

            if(it == string2.end()){
                // nahi mili 
                return false;
            }
            // check for corresponding values
            if(it->second != i.second){
                return false;
            }
        }
        return true;
    }
};


