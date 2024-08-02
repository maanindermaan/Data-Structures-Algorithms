#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    // Har ek char ko lenge

    stack<char> stacks;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // Either it can be OPENING BRACKET
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stacks.push(ch);
        }
        // Or it can be CLOSING BRACKET
        else
        {
            if (!s.empty())
            {
                char topCh = stacks.top(); // returns top element of stack
                if (ch == ')' && topCh == '(')
                { // match kar gaya
                    stacks.pop();
                }
                else if (ch == '}' && topCh == '{')
                { // match kar gaya
                    stacks.pop();
                }
                else if (ch == ']' && topCh == '[')
                { // match kar gaya
                    stacks.pop();
                }

                else
                {
                    // Match nahi kiya brackets not matching
                    return false;
                }
            }
            // Mai closing dekhne aaya or stack empty mila , Stack empty hai iss case mein toh i return false;
            else
            {
                return false;
            }
        }
    }
    if (stacks.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "(){}[][]{}()()";

    if (isValid(s))
    {
        cout << "Yes it is ture";
    }
    else
    {
        cout << "Hatt bkl kuch or de";
    }
    return 0;
}







// bool isValid(string s)
// {
//     stack<char> stacks;
//     for (int i = 0; i < s.length(); i++)
//     {
//         char ch = s[i];

//         // 1. If open insert it
//         if (ch == '(' || ch == '{' || ch == '[')
//         {
//             stacks.push(ch);
//         }
//         else
//         {
//             // 2. If closed then : check for correspoding open in stack when stack is not empty
//             if (!s.empty())
//             {
//                 // 3. Check for closed bracket
//                 char topCh = stacks.top();
//                 if (ch == ')' && topCh == '(')
//                 {
//                     stacks.pop();
//                 }
//                 else if (ch == '}' && topCh == '{')
//                 {
//                     stacks.pop();
//                 }
//                 else if (ch == ']' && topCh == '[')
//                 {
//                     stacks.pop();
//                 }
//                 else{
//                     // Brackets did not matched
//                     return false;
//                 }
//             }
//             else
//             {
//                 // If stack is empty then we can't check for closed so return false.
//                 // This means that there is no open present for closed
//                 return false;
//             }
//         }
//     }
//     if (stacks.empty())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }