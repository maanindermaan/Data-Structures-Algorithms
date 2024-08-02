#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string prefixToInfix(string s) {
    stack<string> st;

    if (s.empty()) {
        return s;
    }
    int i = s.size()-1;
    while (i >= 0) {
        char ch = s[i];
        string initial = "";
        initial.push_back(ch);
        
        if (isalnum(ch)) {
            st.push(initial);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            
            string con = '(' + t1 + ch + t2 + ')';
            st.push(con);
        }
        i--;
    }

    return st.top();
}

int main() {
    string prefix = "*+PQ-MN";
    
    string infix = prefixToInfix(prefix);
    
    cout << "Infix expression: " << infix << endl;
    
    return 0;
}
