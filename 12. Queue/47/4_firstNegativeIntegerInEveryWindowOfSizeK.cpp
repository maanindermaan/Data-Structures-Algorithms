#include <iostream>
#include <deque>
using namespace std;

void solve(int arr[], int size, int k)
{
    // Step 1 : Create a deque
    deque<int> q;

    // step 2 : Process first window of size k
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // step 3 : Remaining Window ko Process krna
    for (int i = k; i < size; i++)
    { // (k+1)th element ka index k hota hai
        // 1. Answer dedo purani window ka
        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // 2. Out of window elements ko remove krdo(piche walo ko hata do)
        while ((!q.empty()) && (i - q.front() >= k))
        {
            q.pop_front();
        }

        // 3. Check Current element for insertion
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // step 4 : Printing answer for last window
    if (q.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << arr[q.front()] << " ";
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;

    int k = 3;

    solve(arr, size, k);
    return 0;
}














// #include <iostream>
// #include <deque>
// using namespace std;

// void solve(int arr[], int size, int k)
// {
//     // step 1 : Create a queue
//     deque<int> dq;

//     // step 2 : process first k nodes
//     for (int i = 0; i < k; i++)
//     {
//         if (arr[i] < 0)
//         {
//             dq.push_back(i);
//         }
//     }

//     // step 3 : process remaining k nodes
//     for (int i = k; i < size; i++)
//     {
//         // 1. Answer nikal lo
//         if (dq.empty())
//         {
//             cout << 0 << " ";
//         }
//         else
//         {
//             cout << arr[dq.front()] << " ";
//         }

//         // 2. Remove krdo
//         if (!dq.empty() && i - dq.front() >= k)
//         {
//             dq.pop_front();
//         }

//         // 3. Insert krdo
//         if (arr[i] < 0)
//         {
//             dq.push_back(i);
//         }
//     }
//     // step 4 : Last wale k liye answer or print krdo
//     if (dq.empty())
//     {
//         cout << 0 << endl;
//     }
//     else
//     {
//         cout << arr[dq.front()] << endl;
//     }
// }

// int main()
// {
//     int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
//     int size = 8;

//     int k = 3;

//     solve(arr, size, k);
//     return 0;
// }