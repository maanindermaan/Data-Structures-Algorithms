#include<iostream>
using namespace std;

int expandAroundIndex(string s , int i , int j){
    int count = 0;
    // Jab tak match krega count increment krdo i peche le jao or j aage lejao
    while((i>=0) && (j<s.length()) && (s[i] == s[j])){
        count++;
        i--;
        j++;
    }
    return count;
}

int palindromicSubstring(string s) {
    int n = s.size();
    int totalCount=0;

    for(int i=0 ; i<n ; i++){
        // ODD
        int oddKaAns = expandAroundIndex(s , i , i);//i and j are on same position help to increease count of element at same index
        totalCount = totalCount+oddKaAns;
        // EVEN
        int evenKaAns = expandAroundIndex(s , i , i+1); //i and j are adjacent to each other
        totalCount = totalCount+evenKaAns;
    }
    return totalCount;
    
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int ans = palindromicSubstring(s);
    cout<<ans;

    return 0;
}





// // 1. Brute Force
// class Solution {
// public:
//     bool checkPalindrome(string word , int i , int j) {
//         while(i <= j) {
//             if(word[i] != word[j]) {
//                     return false;
//             }
//             else {
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }

//     int countSubstrings(string s) {
    
//         int ans = 0;
//         for(int i=0 ; i<s.size() ; i++){
//             for(int j=i ; j<s.size() ; j++){
//                 if(checkPalindrome(s , i , j)){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// 2. Better Solution
// 2. Better Approach
// class Solution {
// public:
//     int expandAroundIndex(string& s , int i ,int j){

//         int cnt = 0;
//         while(i>=0 && j<s.size() && s[i] == s[j]){
//             cnt++;
//             i--;
//             j++;
//         }
//         return cnt;
//     }

//     int countSubstrings(string s) {
//         int total_count = 0;
//         for(int i=0 ; i<s.size() ; i++){
//             // for odd
//             int oddKaAns = expandAroundIndex(s , i , i);
//             total_count += oddKaAns;

//             // for even
//             int evenKaAns = expandAroundIndex(s , i , i+1);
//             total_count += evenKaAns;
//         }
//         return total_count;
//     }
// };