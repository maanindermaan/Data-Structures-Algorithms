#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            j = i;
            while (j < s.size() && (isalpha(s[j]) || isdigit(s[j]))){
                j++;
            }
            if (i != j) {
                arr.push_back(s.substr(i, j - i));
            }
            i = j; // becuase hume har character ke baad repeat ni karwana har word ke baad while loop chalwana hai 
        }

        // Construct the reversed string
        string result = "";
        for (int i = arr.size() - 1; i >= 0; i--) {
            result += arr[i];
            // Last loop ke baad toh i <0 hojega or hume TAB SPACE chahiye bhi nahi 
            if (i > 0) {
                result += " ";
            }
        }

        return result;
    }
};