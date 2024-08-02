#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target)
{
    // BASE CASE
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    // NORMAL CASE
    int topElement = s.top();
    s.pop();

    // RECURSIVE CALL
    insertSorted(s , target);

    // BACKTRACKING
    s.push(topElement); // this pushes the removed top element back to stack. It got removed when a bigger 
    // Element has to be inserted below it
}

void sortingStack(stack<int> &s)
{
    // Base Case
    if (s.empty())
    {
        return; // agar stack hi empty hogya toh kuch ni kar sakte
    }

    int target = s.top(); // mai har baar aage badta rhunga or top wale ko target mein store karata rhunga
    s.pop();
    // Recursive call to get Stack elements into target;
    sortingStack(s);
    // insert at bottom target ko
    insertSorted(s, target);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    s.push(1);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "After Sorting : " << endl;

    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    s.push(1);

    sortingStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
