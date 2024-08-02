// APPROACH -1
// #include<iostream>
// using namespace std;

// bool isValid(string s){
//     // we are trying to null the string s
//     if(s.size() == 0){
//         return true;
//     }

//     int found = s.find("abc");
//     if(found != string::npos){
//         // found
//         string tleft = s.substr(0 , found);
//         string tright = s.substr(found+3 , s.size());

//         // recursive call
//         return isValid(tleft+tright);
//     }
//     return false;
// }

// int main(){
//     string s = "abcabcababcc";

//     if(isValid(s)){
//         cout<<"YES";
//     }
//     else{
//         cout<<"NO";
//     }
// return 0;
// }


// APPROACH - 2
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    // Base Case
    if (s[0] != 'a')
    {
        return false;
    }
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (st.top() == 'a' && !st.empty())
            {
                st.push(ch);
            }
            else
            {
                return false;
            }
        }
        else
        {
            // ch == 'c'
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string s = "abcabcababcc";

    if (isValid(s))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}





// // APPROACH 3
// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.empty()){
//             return true;
//         }

//         if(s.find("abc") != string::npos){
//             s.erase(s.find("abc"), 3);
//             return isValid(s);
//         }
        
//         return false;
//     }
// };





// // APPROACH 4
// class Solution {
// public:
//     bool isValid(string s) {
//         while(s.find("abc") != string::npos){
//             s.erase(s.find("abc"), 3);
//         }
//         if(s.empty()){
//             return true;
//         }
//         return false;
//     }
// };



// APPROACH 5 -> BEST
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i];

            if(ch == 'a'){
                st.push(ch);
            }
            else{
                if(!st.empty() && ch == 'b' && st.top() == 'a'){
                    st.push(ch);
                }
                else if(!st.empty() && ch == 'c' && st.top() == 'b'){
                    st.pop();
                    if(!st.empty()) st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};