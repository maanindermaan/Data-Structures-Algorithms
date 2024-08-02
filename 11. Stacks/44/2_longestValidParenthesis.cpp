#include <iostream>
#include <stack>
using namespace std;

int longestValidParenthesis(string s){
    stack<char> st;
    st.push(-1);
    int maxLen;
    for(int i=0 ; i<s.length() ; i++){
        char ch = s[i];
        // Opening Bracket
        if(ch == '('){
            st.push(i);
        }
        // Closing Bracket
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                // Non empty
                int len = i - st.top();
                maxLen = max(len , maxLen);
            }
        }
    }
    return maxLen;
}

int main()
{
    string s = ")))))))))))))))))))))(((((((((()()()()()()()(())(("; // should return 8

    int ans = longestValidParenthesis(s);
    
    cout<<"Maximum valid length is : "<<ans;
    return 0;
}