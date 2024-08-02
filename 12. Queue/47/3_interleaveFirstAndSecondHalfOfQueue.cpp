// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// void interleave(queue<int> &q)
// {
//     vector<int> arr;
//     vector<int> ans;

//     // 1. Queue se elements array mein dalldo
//     while (!q.empty())
//     {
//         int element = q.front();
//         q.pop();
//         arr.push_back(element);
//     }

//     // 2. array mein operation perform krlo
//     int i = 0;
//     int j = arr.size() / 2;
//     if (arr.size() % 2 == 0)
//     {
//         // even case
//         while (i < arr.size() / 2)
//         {
//             ans.push_back(arr[i]);
//             ans.push_back(arr[j]);

//             i++;
//             j++;
//         }
//     }
//     else
//     {
//         // odd case
//         while (i <= arr.size() / 2)
//         {
//             ans.push_back(arr[i]);
//             ans.push_back(arr[j]);

//             i++;
//             j++;
//         }
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         q.push(ans[i]);
//     }
// }

// int main()
// {
//     queue<int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     q.push(50);
//     q.push(60);
//     q.push(70);
//     q.push(80);
//     q.push(90);
//     q.push(100);

//     cout << "before interleaving QUEUE" << endl;
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;
//     cout << endl;
//     cout << endl;

//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     q.push(50);
//     q.push(60);
//     q.push(70);
//     q.push(80);
//     q.push(90);
//     q.push(100);

//     interleave(q);

//     cout << "after interleaving QUEUE";
//     cout << endl;
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     return 0;
// }






// Approach -2
#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q)
{
    queue<int> firstHalf;
    int n = q.size();
    int k = n / 2;
    int count = 0;

    if (n == 0)
    {
        return;
    }

    // 1. Queue se half elements firstHalf mein daldo
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        firstHalf.push(temp);
        count++;

        if (count == k)
        {
            break;
        }
    }

    // 2. now pop from 1 and push into q and pop from q and push at back in queue
    while (!firstHalf.empty() && !q.empty())
    {
        int first = firstHalf.front();
        firstHalf.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    // if (n % 2 != 0) ODD CASE
    // if (n&1) // ODD CASE
    if (n % 2 == 1) // ODD CASE
    {
        // ODD CASE
        int second = q.front();
        q.pop();
        q.push(second);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    cout << "before interleaving QUEUE" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << endl;
    cout << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    interleave(q);

    cout << "after interleaving QUEUE";
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}