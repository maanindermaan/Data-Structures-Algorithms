#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseKElementsOfQueue(queue<int> &q, int k)
{
    int n = q.size();
    stack<int> s;

    if(k==0 || k>n){
        return;
    }


    // 1. Put k elements of queue in stack
    // while (k--)
    // {
    //     int element = q.front();
    //     q.pop();

    //     s.push(element);
    // }
    int count = 0;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
        count++;

        if (count == k)
        {
            break;
        }
    }

    // 2. Put k elements from stack into queue
    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }

    // 3. Take n-k elements from queue front and put them back
    // int diff = q.size() - k;
    // while(diff--){
    //     int temp = q.front();
    //     q.pop();
    //     q.push(temp);
    // }

    count = 0;
    int diff = n - k;
    while (!q.empty() && diff != 0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if (count == diff)
        {
            break;
        }
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    cout << "before reversing k elements : QUEUE" << endl;
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    reverseKElementsOfQueue(q, k);

    cout << "after reversing k elements : QUEUE";
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}