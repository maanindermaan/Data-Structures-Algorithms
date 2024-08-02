#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void removeDuplicates(string &str)
{

    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (s.empty())
        {
            s.push(ch);
        }
        else if (!s.empty() && ch == s.top())
        {
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }

    str.clear(); // clears the orignal string

    while (!s.empty())
    {
        char temp = s.top();
        str.push_back(temp);
        s.pop();
    }

    reverse(str.begin(), str.end());
}

int main()
{
    string s = "azxxzy";
    cout << endl;
    cout << endl;
    cout << s;
    removeDuplicates(s);
    cout << endl;
    cout << endl;

    cout << s;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}




// 2. Approach
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(int i=s.size()-1 ; i>=0 ; i--){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] == st.top()){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        s.clear();
        while(!st.empty()){
            char ch = st.top();
            st.pop();

            s.push_back(ch);
        }
        return s;
    }
};