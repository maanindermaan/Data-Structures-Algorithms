#include <iostream>
#include <stack>
using namespace std;

int countReversal(string s)
{
    // odd size not possible
    if (s.size() & 1)
    {
        return -1;
    }

    int ans = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        // opening bhej rhe hai
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            // closing bhej rhe hai
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                // agar match nahi hua toh
                st.push(ch);
            }
        }
    }
    // if stack is still not empty then
    while (!st.empty())
    {
        char a = st.top();
        st.pop();

        char b = st.top();
        st.pop();

        if (a == b)
        {
            ans += 1;
        }
        else
        {
            ans += 2;
        }
    }
    return ans;
}

int main()
{
    string s = ")(())(((";
    cout << countReversal(s);
    return 0;
}