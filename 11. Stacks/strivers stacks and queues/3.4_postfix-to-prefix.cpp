#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string postfixToPrefix(string s) {
    stack<string> st;

    if (s.empty()) {
        return s;
    }
    int i = 0;
    while (i < s.size()) {
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
            
            string con = ch + t2 + t1;
            st.push(con);
        }
        i++;
    }

    return st.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    
    string prefix = postfixToPrefix(postfix);
    
    cout << "Prefix expression: " << prefix << endl;
    
    return 0;
}
