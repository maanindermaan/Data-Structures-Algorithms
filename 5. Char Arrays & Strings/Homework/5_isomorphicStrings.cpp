#include<iostream>
#include<map>
using namespace std;

bool isomorphicStrings(string s , string t){
    int hash[256] = {0}; // mapping of each char of ' s ' to each char of ' t '
    bool istCharMapped[256] = {0}; // stores if t[i] char already mapped with s[i]

    for(int i=0 ; i<s.size() ; i++){
        if(hash[s[i]] == 0 && (istCharMapped[t[i]]==0)){ // s wale hash mein bhi khud ni map hua hua or t wale hash mein bhi kuch nahi map hua hai tab hi aage bado 
            hash[s[i]] = t[i]; // s ko t se map krdiya
            istCharMapped[t[i]] = true; // t ko true mark krdiya ki haan bhai you are mappped now 0 se 1 krdiya
        } 
    }

    for(int i=0 ; i<s.size() ; i++){
        if(char(hash[s[i]]) != t[i]){// we have to covert hash into char as t[i] gives char values only
            return false;
        } 
    }
    return true;
}

int main(){
    string s = "paper";
    string t = "title";

    if(isomorphicStrings(s,t)){
        cout<<"YES";
    }
    else{
        cout<<"NO";    
    }

return 0;
}




// My approach
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false; // Different lengths, cannot be isomorphic
        }

        unordered_map<char, char> map;

        // for s
        for (int i = 0; i < s.size(); i++) {
            // key found
            if (map.find(s[i]) != map.end()) {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                map[s[i]] = t[i];
            }
        }

        // for t
        map.clear(); // Clear the map for the second loop
        for (int i = 0; i < t.size(); i++) {
            // key found
            if (map.find(t[i]) != map.end()) {
                if (map[t[i]] != s[i]) {
                    return false;
                }
            } else {
                map[t[i]] = s[i];
            }
        }

        return true;
    }
};