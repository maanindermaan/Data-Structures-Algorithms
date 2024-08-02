#include<iostream>
using namespace std;
int main(){

return 0;
}

// class Solution {
// public:
//     string largestOddNumber(string num) {
//         string maxi;
//         int maxnum = INT_MIN;
//         if((num[num.size()-1]-'0') % 2 == 1){
//             // last digit odd hai matlab it is the largest only
//             return num;
//         }
//         else{
//             int number = INT_MIN;
//             // last digit even -> check by removing one digit from last
//             if(num.size() < 10){
//                 number = stoi(num);
//             }
//             while(number > 0){
//                 number = number/10;
//                 // check whether it is odd or not now and compare with maxnum
//                 if(number % 2 ==1 && number > maxnum){
//                     maxnum = number;
//                     maxi = to_string(number);
//                 }
//             }
//             // last digit even -> break it and then check individually
//             for(char i : num){
//                 // it is odd and greater than max num
//                 if(i-'0' > maxnum && (i-'0') %2 == 1){
//                     maxnum = i-'0';
//                     maxi = i;
//                 }
//             }
//         }
//         if(maxnum != INT_MIN){
//             return maxi;
//         }
//         return "";
//     }
// };


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            // har ek element ka last digit check krte jao jo odd dikhe vohi substring banado
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};