// APPROACH 1

// #include<iostream>
// #include<stack>
// #include<queue>
// using namespace std;

// void push(int x, stack<int>& s1, stack<int>& s2) {
//     // Move all elements from s1 to s2
//     while (!s1.empty()) {
//         int temp = s1.top();
//         s1.pop();
//         s2.push(temp);
//     }

//     // Add x to s1
//     s1.push(x);

//     // Move all elements back from s2 to s1
//     while (!s2.empty()) {
//         int temp = s2.top();
//         s2.pop();
//         s1.push(temp);
//     }
// }

// void pop(stack<int>&s1 , stack<int>&s2){
//     s1.pop();
// }

// int front(stack<int>&s1 , stack<int>&s2){
//     int temp = s1.top();
//     // s1.pop();
//     return temp;
// }

// int main(){
//     queue<int>q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);

//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();

//     cout<<"Using Stack"<<endl;
//     stack<int>s1;
//     stack<int>s2;
//     push(10 , s1 , s2);
//     push(20 , s1 , s2);
//     push(30 , s1 , s2);
//     push(40 , s1 , s2);
//     cout<< front(s1 , s2)<<endl;
//     pop(s1, s2);
//     cout<< front(s1 , s2)<<endl;
//     pop(s1, s2);
//     cout<< front(s1 , s2)<<endl;
//     pop(s1, s2);
//     cout<< front(s1 , s2)<<endl;
//     pop(s1, s2);
// return 0;
// }




// // Approach 2s

#include <iostream>
#include <stack>
using namespace std;

class Myqueue
{
public:
    stack<int> s1;
    stack<int> s2;

    Myqueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (!s2.empty())
        {
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            s2.pop();
        }
    }

    int front(){
        int ans;
        if (!s2.empty())
        {
            ans = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            ans = s2.top();
        }
        return ans;
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};

int main()
{

    return 0;
}
