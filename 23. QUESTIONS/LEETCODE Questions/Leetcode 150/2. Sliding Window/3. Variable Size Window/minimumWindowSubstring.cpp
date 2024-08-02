// class Solution {
// public:
//     // OPTIMISED WINDOW TECHNIQUE
//     string minWindow(string s, string t) {
//         int start = 0;

//         int len1 = s.length();
//         int len2 = t.length();

//         unordered_map<char , int>strMap;
//         unordered_map<char , int>ttrMap;

//         int ansLen = INT_MAX;
//         int ansIndex = -1;

//         int count = 0;

//         if (len1 < len2)
//         {
//             return "";
//         }

//         // 1. marking ttr map elements
//         for(int i=0 ; i<len2 ; i++){
//             ttrMap[t[i]]++;
//         }

//         // 2. For strMap elements
//         for(int i=0 ; i<len1 ; i++){
//             char ch = s[i];
//             strMap[ch]++;

//             if(strMap[ch] <= ttrMap[ch]){
//                 count++;
//             }

//             // window milgayi
//             if(count == len2){
//                 // ab iss window ko optmise karo
//                 // 1. Freq decrement
//                 // 2. Start increment
//                 // 3. Ans update
//                 // first element ko dekho jo ki start pe pada hai
//                 while(strMap[s[start]] > ttrMap[s[start]] || ttrMap[s[start]] == 0){
//                     // 1.
//                     if(strMap[s[start]] > ttrMap[s[start]]){
//                         strMap[s[start]]--;
//                     }

//                     // 2.
//                     start++;
//                 }
//                 // 3. 
//                 int lengthOfWindow = i-start+1;
//                 if (lengthOfWindow < ansLen)
//                 {
//                     ansLen = lengthOfWindow;
//                     ansIndex = start;
//                 }
//             }
//         }
//         if(ansIndex == -1){
//             return "";
//         }
//         return s.substr(ansIndex , ansLen);
//     }
// };