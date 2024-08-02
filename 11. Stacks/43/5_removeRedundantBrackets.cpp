#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string &s)
{
    stack<char> stacks;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // ch mera opening hai ya operator hai
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            stacks.push(ch);
        }
        // ch mera closing hai ya letter hai
        else
        {
            if (ch == ')')
            {
                bool operatorFound = false;
                // we check for operator
                while (stacks.top() != '(')
                {
                    // Tab tak chalyenge jab tak opening na miljaye
                    int top = stacks.top();
                    if (top == '+' || top == '-' || top == '/' || top == '*')
                    {
                        operatorFound = true;
                    }
                    stacks.pop();
                }
                if(operatorFound == false){ // koi operator nahi mila toh redundant hoga pakka
                    return true;
                }
                stacks.pop();
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
