// #include <iostream>
// #include <stack>
// #include <queue>
// using namespace std;

// void reverseQueue(queue<int> &q)
// {
//     stack<int> s;
//     // 1. Put all elements of queue in stack
//     while (!q.empty())
//     {
//         int element = q.front();
//         q.pop();

//         s.push(element);
//     }

//     // 2. Put all elements from stack into queue
//     // Base Case
//     while (!s.empty())
//     {
//         int element = s.top();
//         s.pop();

//         q.push(element);
//     }
// }

// int main()
// {
//     queue<int> q;
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);
//     cout << "before reversing QUEUE" << endl;
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;
//     cout << endl;
//     cout << endl;

//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);

//     reverseQueue(q);

//     cout << "after reversing QUEUE";
//     cout << endl;
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     return 0;
// }










// RECURSIVE APPROACH
#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    // Base Case
    if(q.empty()){
        return;
    }

    // 1 case tum sambhal lo
    int frontElement = q.front();
    q.pop();

    // Recursive Call
    reverseQueue(q);

    // BackTracking
    q.push(frontElement);
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    cout << "before reversing QUEUE" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << endl;
    cout << endl;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);

    cout << "after reversing QUEUE";
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}