#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string &s)
{
    stack<char>st;

    for(int i=0 ; i<s.size() ; i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool operatorValue = false;
                while(st.top() != '('){
                    char top = st.top();
                    if( top == '+' || top == '-' || top == '/' || top == '*'){
                        operatorValue = true;
                    }
                    st.pop();
                }
                if(operatorValue == false){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string s;

    cout << "Enter an expression: ";
    cin >> s;

    if (checkRedundantBrackets(s))
        cout << "Redundant brackets are present." << endl;
    else
        cout << "No redundant brackets found." << endl;

    return 0;
}
