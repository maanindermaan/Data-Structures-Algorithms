#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int stringToInteger(string s) {
    int num = 0;
    int i = 0; // used to iterate over a string
    int sign = 1; // Initially positive

    // 1) Checking empty spaces
    while (s[i] == ' ') {
        i++;
    }

    // 2) Checking sign and i such that i is not out of bound
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) { // Changed 'while' to 'if'
        if (s[i] == '-') {
            sign = -1; // Fixed sign assignment
        }
        i++;
    }

    // 3) Only printing digits not characters and they are digits only
    while (i < s.size() && isdigit(s[i])) { // Changed '>' to '<' in condition
        // 4) checking out of bound
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            if (sign == -1) {
                return INT_MIN; // Return immediately instead of assigning value
            } else {
                return INT_MAX; // Return immediately instead of assigning value
            }
        }
        num = num * 10 + (s[i] - '0');
        i++; // Increment i inside the loop
    }
    return num * sign;
}

int main() {
    string s;
    cout << "Enter the string you want to convert to integer: ";
    cin >> s;

    int ans = stringToInteger(s);
    cout << "The converted value from string to int is: " << ans;
    return 0;
}


// 1.Bas trailing digits ka chod hai
class Solution {
public:
    int myAtoi(string ans) {
        vector<int>nums;
            
        for(int i=0 ; i<ans.size() ; i++){
            if((static_cast<int>(ans[i]) - 48) > 0 && (static_cast<int>(ans[i]) - 48) < 10){
                nums.push_back(static_cast<int>(ans[i]) - 48);
            }
        }
        
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result = result * 10 + nums[i];
        }

        for(int i=0 ; i<ans.size() ; i++){
            if(static_cast<int>(ans[i]) - 48 == -3){
                result = result*-1;
            }    
        }
        return result;
    }   
};



// 2.Bas overflow ka chod hai
int myAtoi(string ans) {
        vector<int>nums;
            
        for(int i=0 ; i<ans.size() ; i++){
            if((static_cast<int>(ans[i]) - 48) > 0 && (static_cast<int>(ans[i]) - 48) < 10){
                nums.push_back(static_cast<int>(ans[i]) - 48);
            }
            if(nums.size() == 0 && static_cast<int>(ans[i]) - 48 != -16 && static_cast<int>(ans[i]) - 48 != -5 && static_cast<int>(ans[i]) - 48 != -3){
                return 0;
            }
        }
        
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = result * 10 + nums[i];
        }

        for(int i=0 ; i<ans.size() ; i++){
            if(static_cast<int>(ans[i]) - 48 == -3){
                result = result*-1;
            }    
        }
        return result;
    }   



// 3. THodi kamm chod wala
class Solution {
public:
    int myAtoi(string ans) {
        vector<int>nums;
        int sign = 1;
            
        for(int i=0 ; i<ans.size() ; i++){
            if(isdigit(ans[i])){
                nums.push_back(ans[i] - '0');
            }
            if(ans[i] == '-'){
                sign *= -1;
            }
        }
        
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(result > INT_MAX/10 || result == INT_MAX/10){
                if(sign == 1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            result = result * 10 + nums[i];
        }
        
        result *= sign;

        return result; 
    }
};