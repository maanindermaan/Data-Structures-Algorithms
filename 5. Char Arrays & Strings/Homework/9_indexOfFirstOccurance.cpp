// Method -1 More Optimised
#include<iostream>
using namespace std;

int firstOccurance(string s ,string t){
    int n = t.length();    
    int start = 0;
    int ans;
    // int end = start + n;

    while(start+n <= s.length()){
        if(s.substr(start , n) != t){
            start++;
        }
        else if(s.substr(start , n) == t){
            ans = start;
            break;
        }
    }
    if(s.substr(start , n) != t){
        return -1;
    }
    return ans;
}

int main(){
    string s = "leetcodesadhero";
    string t = "hero";
    int ans = firstOccurance(s,t);
    cout<<"The first occurance is : "<<ans;
return 0;
}


// Method - 1
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int ans = 0;


        while(ans + n <= haystack.size()){
            if(haystack.substr(ans , n) != needle){
                ans++;
            }
            else if(haystack.substr(ans , n) == needle){
                return ans;
            }
        }
        return -1;
    }
};



// Method -2 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) != string::npos){
            return haystack.find(needle);
        }
        return -1;
    }
};



