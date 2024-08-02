#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == ']')
        { // ch == ] clsoing bracket
            string stringToRepeat = "";
            while (!st.empty() && st.top() != "[")
            {
                string top = st.top();
                stringToRepeat += top;
                st.pop();
            }
            st.pop();

            string numericalTimes = "";

            while (!st.empty() && isdigit(st.top()[0]))
            {
                numericalTimes += st.top();
                st.pop();
            }
            reverse(numericalTimes.begin(), numericalTimes.end());

            int n = stoi(numericalTimes); // this is string to integer

            string currentDecodeString = "";
            while (n--)
            {
                currentDecodeString += stringToRepeat;
            }
            st.push(currentDecodeString);
        }
        else
        {
            string temp(1, ch); // converting char to string
            st.push(temp);
        }
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "3[ab]";

    string ans = decodeString(s);

    cout << ans;
    return 0;
}

// #include <iostream>
// #include <stack>
// using namespace std;

// string decodeString(string s) {
//     stack<string> st;

//     for (int i = 0; i < s.size(); i++) {
//         char ch = s[i];

//         if (ch == ']') {
//             string stringToRepeat = "";

//             // Pop elements until we reach the opening bracket '['
//             while (!st.empty() && st.top() != "[") {
//                 string top = st.top();
//                 st.pop();
//                 stringToRepeat = top + stringToRepeat;
//             }

//             // Pop the opening bracket '['
//             st.pop();

//             string numericalTimes = "";

//             // Continue popping digits until we reach a non-digit or the stack is empty
//             while (!st.empty() && isdigit(st.top()[0])) {
//                 numericalTimes = st.top() + numericalTimes;
//                 st.pop();
//             }

//             int n = stoi(numericalTimes); // Convert the string to an integer

//             string currentDecodeString = "";
//             while (n--) {
//                 currentDecodeString += stringToRepeat;
//             }
//             st.push(currentDecodeString);
//         } else {
//             string temp(1, ch); // converting char to string
//             st.push(temp);
//         }
//     }

//     string ans;
//     while (!st.empty()) {
//         ans += st.top();
//         st.pop();
//     }

//     return ans;
// }

// int main() {
//     string s = "3[ab]";

//     string ans = decodeString(s);

//     cout << ans;
//     return 0;
// }
