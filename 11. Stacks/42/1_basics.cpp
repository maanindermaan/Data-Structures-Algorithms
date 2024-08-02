#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40); // sabse uper hai yeah

    // removing
    st.pop();

    // checking element on top
    cout << st.top() << endl;

    // Size of stack
    cout << st.size() << endl;

    if (st.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
        cout << "stack is not empty" << endl;

    // Printing
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << s.top() << endl; // uper wala print krdo
        s.pop();                 // uper wala hatado or agla print hoga ab loop mein
    }
    return 0;
}