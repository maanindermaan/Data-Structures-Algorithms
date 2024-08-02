#include<iostream>
using namespace std;
int main(){
    
return 0;
}

int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;

        unordered_map<char, bool> strMap;

        int ansLen = 0;

        while (j < s.size()) {
            // If the character at s[j] is not in the current substring, mark it as true.
            // 1. NOT PRESENT
            if (!strMap[s[j]]) {
                strMap[s[j]] = true;
                ansLen = max(ansLen, j - i + 1);
                j++;
            } 
            // 2. PRESENT, MOVE WINDOW FORWARD
            else{
                // If the character at s[j] is already in the substring, move the start of the substring.
                strMap[s[i]] = false;
                i++;
            }
        }
        return ansLen;
    }