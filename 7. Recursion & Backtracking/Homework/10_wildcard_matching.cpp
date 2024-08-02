#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    bool isRecursive(const string& s, const string& p, int i, int j) {
        // Base cases
        if (i == s.size() && j == p.size()) {
            return true;  // Both strings and pattern consumed
        }
        if (j == p.size()) {
            return false; // Pattern consumed but string not
        }

        // Handle '*' wildcard: matches zero or more characters
        if (p[j] == '*') {
            // Match zero characters or one character and recurse
            return isRecursive(s, p, i, j + 1) || (i < s.size() && isRecursive(s, p, i + 1, j));
        }

        // Handle '?' or exact match
        if (i < s.size() && (s[i] == p[j] || p[j] == '?')) {
            return isRecursive(s, p, i + 1, j + 1);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return isRecursive(s, p, 0, 0);
    }
};



// Same method slightly different
class Solution {
public:
    bool isrecursive(string& s , int si , string& p  , int pi){
        // base case
        if(si == s.size() && pi == p.size()){
            return true;
        }

        if(si == s.size() && pi < p.size()){
            // iss case mein agar saare estric hai tohi true hoga
            while(pi < p.size()){
                if(p[pi] != '*'){
                    return false;
                }
                pi++;
            }
            return true;
        }



        // single char matching
        if(s[si] == p[pi] || p[pi] == '?'){
            return isrecursive(s , si+1 , p , pi+1);
        }

        // estric
        if(p[pi] == '*'){
            // treat '*' as empty or null
            bool caseA = isrecursive(s , si , p , pi+1);

            // treat '*' consume once character
            bool caseB = isrecursive(s , si+1 , p , pi);

            return caseA || caseB;
        }

        // char doesn't match 
        return false;
    }

    bool isMatch(string s, string p) {
        int si = 0; // pointer for s string
        int pi = 0; // pointer for p string

        return isrecursive(s , si , p , pi);
    }
};
