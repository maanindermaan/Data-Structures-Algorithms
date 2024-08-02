// 1st method (with BT and STACK)
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool isvalid(const string& element){
    stack<char> s;
    for (char ch : element) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

void recursive(int n, vector<string>& arr, string element) {
    if (element.length() == 2 * n) {
        if (isvalid(element)) {
            arr.push_back(element);
        }
        return;
    }

    element.push_back('(');
    recursive(n, arr, element);
    element.pop_back();

    element.push_back(')');
    recursive(n, arr, element);
    element.pop_back();
}

vector<string> validParenthesis(int n) {
    vector<string> arr;
    string element;
    recursive(n, arr, element);
    return arr;
}


// 2nd method (without BT and STACKS)
#include <vector>
#include <string>
using namespace std;

void recursive(int n, vector<string>& arr, string element, int open, int close) {
    // base case: if the current string length is 2 * n, we've generated a valid string
    if (element.length() == 2 * n) {
        arr.push_back(element);
        return;
    }

    // if we can still add an opening parenthesis, do so
    if (open < n) {
        recursive(n, arr, element + '(', open + 1, close);
    }

    // if we can still add a closing parenthesis, do so
    if (close < open) {
        recursive(n, arr, element + ')', open, close + 1);
    }
}

vector<string> validParenthesis(int n) {
    vector<string> arr;
    recursive(n, arr, "", 0, 0);
    return arr;
}
