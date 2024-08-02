#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>>& M, int n)
{
    stack<int> st;

    // 1. Push all persons into stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // 2. Running discard method to get a mightBeCelebrity
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b
        if (M[a][b])
        {
            // a is not celebrity , b might be
            st.push(b);
        }
        else
        {
            // b is not celebrity , a might be
            st.push(a);
        }
    }

    // 3. Check whether this mightBeCelbrity is actual celebrity or not
    // Check whether single person is celebrity or not
    int mightBeCelbrity = st.top();
    st.pop();

    // Celebrity should not know anyone
    // Rows should be 0
    for (int i = 0; i < n; i++)
    {
        if (M[mightBeCelbrity][i] != 0)
        {
            return -1; // Not a celebrity
        }
    }

    // Everyone should know celebrity
    for (int i = 0; i < n; i++)
    {
        if (M[i][mightBeCelbrity] == 0 && i != mightBeCelbrity)
        {              // diagonal should not be 0
            return -1; // Not a celebrity
        }
    }

    // If we crosses everything then mightBeCelebrity is the celebrity
    return mightBeCelbrity;
}

int main()
{
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};

    int n = 3;

    cout << celebrity(M, n);
    return 0;
}











// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// int celebrity(vector<vector<int>>& M, int n)
// {
//     stack<int> st;

//     // 1. Push all persons into stack
//     for (int i = 0; i < n; i++)
//     {
//         st.push(i);
//     }

//     // 2. Running discard method to get a potential celebrity
//     while (st.size() != 1)
//     {
//         int a = st.top();
//         st.pop();
//         int b = st.top();
//         st.pop();

//         // if a knows b
//         if (M[a][b])
//         {
//             // a is not a potential celebrity, b might be
//             st.push(b);
//         }
//         else
//         {
//             // b is not a potential celebrity, a might be
//             st.push(a);
//         }
//     }

//     // 3. Check whether the potential celebrity is an actual celebrity or not
//     int potentialCelebrity = st.top();
//     st.pop();

//     // Celebrity should not know anyone
//     // Rows should be 0
//     for (int i = 0; i < n; i++)
//     {
//         if (M[potentialCelebrity][i] != 0)
//         {
//             return -1; // Not a celebrity
//         }
//     }

//     // Everyone should know the potential celebrity
//     for (int i = 0; i < n; i++)
//     {
//         if (M[i][potentialCelebrity] != 1 && i != potentialCelebrity)
//         {
//             return -1; // Not a celebrity
//         }
//     }

//     // If we cross everything, then the potential celebrity is the celebrity
//     return potentialCelebrity;
// }

// int main()
// {
//     vector<vector<int>> M = {
//         {0, 1, 0},
//         {0, 0, 0},
//         {0, 1, 0}};

//     int n = 3;

//     cout << celebrity(M, n);
//     return 0;
// }
