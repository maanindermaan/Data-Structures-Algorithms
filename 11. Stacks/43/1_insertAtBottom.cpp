// #include <iostream>
// #include <stack>
// using namespace std;

// void solve(stack<int> &s, int target)
// {
//     // Base case
//     if (s.empty())
//     {
//         s.push(target);
//         return;
//     }
//     int temp = s.top();// top wala daldo 
//     s.pop(); // agar top wala daldia toh usko nikaldo taaki next dal sake
//     // recursive call
//     solve(s, target);

//     // Backtracking
//     s.push(temp);
// }

// void insertAtBottom(stack<int> &s)
// {
//     if (s.empty())
//     {
//         cout << "Stack is empty can't push";
//     }

//     int target = s.top();
//     s.pop();

//     solve(s, target);
// }

// int main()
// {
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);

//     insertAtBottom(s);

//     while(!s.empty()){
//         cout<<s.top()<<endl;
//         s.pop();
//     }

//     return 0;
// }











// Reducing Number of Functions
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{
    // Base case
    if (s.empty())
    {
        s.push(target); // agar list khali hogai toh bhai mere simple si baat hai targetNode dalde or return karja
        return;
    }
// Agar empty nahi hui toh list ko empty kar temp mein data dalta reh backtrack krte hue vapis dedio
    int temp = s.top();
    s.pop(); // nikalne ke bad delete bhi to karna padega bhaiya
    // recursive call
    insertAtBottom(s, target);

    // Backtracking
    s.push(temp);
}


// void insertAtBottom(stack<int> &s , int target){
//     // 1. Base Case
//     if(s.empty()){
//         s.push(target);
//         return;
//     }

//     // 2. Storing the top element
//     int temp = s.top();

//     // 3. Popping the stored element
//     s.pop();

//     // 4. Recursive Call
//     insertAtBottom(s , target);

//     // 5. BackTracking
//     s.push(temp);
// }


int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    if (s.empty())
    {
        cout << "Stack is empty can't push";
    }

    int target = s.top();
    s.pop();

    insertAtBottom(s , target);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}



