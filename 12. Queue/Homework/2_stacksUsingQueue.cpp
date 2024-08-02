// // APPROACH - 1 -> Using 2 queues
#include <iostream>
// #include <queue>
// using namespace std;

// class Mystack
// {
// public:
//     queue<int> q1;
//     queue<int> q2;

//     Mystack()
//     {

//     }

//     void push(int x)
//     {
//         // 1. Push into q2
//         q2.push(x);

//         // 2. Transfer all elements from q1 to q2
//         while(!q1.empty()){
//             int temp = q1.front();
//             q1.pop();
//             q2.push(temp);
//         }

//         // 3. Transfer all elements from q2 to q1
//         while(!q2.empty()){
//             int temp = q2.front();
//             q2.pop();
//             q1.push(temp);
//         }

//     }

//     void pop()
//     {
//         // Also check overflow condition
//         q1.pop();
//     }

//     int front(){
//         // also check underflow condition
//         return q1.front();
//     }

//     bool empty(){
//         return q1.empty() && q2.empty();
//     }
// };

// int main()
// {
//     Mystack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);

//     s.pop();

//     cout<<s.front();
//     return 0;
// }






// APPROACH - 2 -> Using 1 queue
#include <iostream>
#include <queue>
using namespace std;

class Mystack
{
public:
    queue<int> q;

    Mystack()
    {

    }

    void push(int x)
    {
        // 1. Push into q
        q.push(x);

        // 2. Loop till size-1 for reversal
        for(int i=0 ; i<q.size()-1 ; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    void pop()
    {
        // Also check overflow condition
        q.pop();
    }

    int front(){
        // also check underflow condition
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main()
{
    Mystack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();

    cout<<s.front();
    return 0;
}
