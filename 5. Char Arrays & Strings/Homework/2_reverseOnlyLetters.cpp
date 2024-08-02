#include<iostream>
using namespace std;

void reverseOnlyLetters(string s){
    int start = 0;
    int end = s.size()-1;

    while(start<=end){
        if(isalpha(s[start]) && isalpha(s[end])){
            swap(s[start] , s[end]);
            start++;
            end--;
        }
        else if(!isalpha(s[start])){
            start++;
        }
        else if(!isalpha(s[end])){
            end--;
        }
    }
    cout<<s;
}

int main(){
    string s = "Test1ng-Leet=code-Q!";
    reverseOnlyLetters(s);
return 0;
}




// Good try
class Solution {
public:
    string reverseOnlyLetters(string s) {
        // 65-122
        int i=0; 
        int j=s.length()-1;

        while(i<=j){
            int letter1 = s[i];
            int letter2 = s[j];
            // we can swap
            if(letter1 > 64 && letter1 < 91 || letter1 > 96 && letter1 < 123 && letter2 > 64 && letter2 < 91 || letter2 > 96 && letter2 < 123){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            else if(letter1 < 65 || letter1 > 90 && letter1 < 97 || letter1 > 122){
                i++;
            }
            else if(letter2 < 65 || letter2 > 90 && letter2 < 97 || letter2 > 122){
                j--;
            }
        }
        return s;
    }
};