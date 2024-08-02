#include<iostream>
using namespace std;

void reverseString(string s , int i){
    
    // Base Case
    if(i>=s.size()){
        return;
    }

    // Baaki recursion sambhal lega
    reverseString(s,i+1);
    
    // Ek case solve kardo
    cout<<s[i];
}

int main(){
    string s = "maninder";
    int i =0 ;
    reverseString(s , i);
return 0;
}


class Solution
{
    public:
    
    void recursiveReverse(string& str , int i , int j){
        // base case
        if(i>=j){
            return;
        }
        swap(str[i] , str[j]);
        recursiveReverse(str , i+1 , j-1);
    }
    
    string reverseWord(string str)
    {
        int i=0;
        int j=str.size()-1;
        
        recursiveReverse(str , i , j);
        
        return str;
    }
};