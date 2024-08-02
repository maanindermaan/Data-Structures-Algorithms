// class Solution {
// public:

//     bool isNonNumerical(char c){
//         return !isdigit(c);
//     }
//     bool isPalindrome(string s) {

//         // 1. converting upper case to lower case
//         for(int i=0 ; i<s.size() ; i++){
//             s[i] = tolower(s[i]);
//         }

//         // 2. Removing non numerical data
//         s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());

//         // 3. Removing spaces
//         s.erase(remove(s.begin() , s.end() , ' ') , s.end());

//         int i=0 , j = s.size()-1;
//         while(i<=j){
//             if(s[i] != s[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// };





// More optimal code

