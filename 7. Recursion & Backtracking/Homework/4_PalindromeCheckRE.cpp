#include<iostream>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
public:

    bool checkRecursive(string s , int i , int j){
        // base case
        if(i >= j){
            return true;
        }

        while(!isalnum(s[i]) && i < j){
            i++;
        }
        while(!isalnum(s[j]) && i < j){
            j--;
        }

        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }

        return checkRecursive(s , i+1 , j-1);
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        return checkRecursive(s , i , j);
    }
};


// 2.
class Solution {
public:

    bool isAlphanumeric(char c) {
        return isalnum(c) != 0;
    }

    bool isSameChar(char a, char b) {
        return tolower(a) == tolower(b);
    }

    bool checkPalindrome(string s, int left, int right) {
        // Base case: If pointers meet or cross each other
        if (left >= right) {
            return true;
        }

        // Move left pointer until it points to an alphanumeric character
        while (left < right && !isAlphanumeric(s[left])) {
            left++;
        }

        // Move right pointer until it points to an alphanumeric character
        while (left < right && !isAlphanumeric(s[right])) {
            right--;
        }

        // If characters at current positions are not the same, return false
        if (!isSameChar(s[left], s[right])) {
            return false;
        }

        // Recursively check the remaining substring
        return checkPalindrome(s, left + 1, right - 1);
    }

    bool isPalindrome(string s) {
        return checkPalindrome(s, 0, s.size() - 1);
    }
};