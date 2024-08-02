#include<iostream>
using namespace std;

bool isVowel(char ch){
    ch = tolower(ch); //conerting to lowe case
    // if(ch == 'a' || ch == 'e' || ch == 'i' || ch=='o' || ch == 'u'){
    //     return true;
    // }
    // return false;
    // OR
    return ch == 'a' || ch == 'e' || ch == 'i' || ch=='o' || ch == 'u'; 

}

void reverseVowels(string s){
    int start = 0;
    int end = s.size()-1;

    while(start < end){
        if(isVowel(s[start]) && isVowel(s[end])){
            swap(s[start] , s[end]);
            start++;
            end--;
        }
        else if(!isVowel(s[start])){
            start++;
        }
        else{
            end--;
        }
    }
    cout<<s;
}

int main(){
    string s = "leetcode";
    reverseVowels(s);
return 0;
}