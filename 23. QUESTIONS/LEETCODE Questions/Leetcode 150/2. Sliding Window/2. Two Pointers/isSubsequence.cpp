class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 1. base condition
        if(s.size() > t.size()){
            return false;
        }

        int i = 0; // pointing to t
        int j = 0; // pointing to s

        while(i<t.size() && j<s.size()){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j == s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};