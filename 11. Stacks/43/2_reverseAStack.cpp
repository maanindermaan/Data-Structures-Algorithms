#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int>&s , int topNode){
    if(s.empty()){
        s.push(topNode);
        return;
    }
    int temp = s.top();
    s.pop();

    insertAtBottom(s , topNode);

    s.push(temp);
}


void reverseStack(stack<int>&s){
    // Base Case
    if(s.empty()){
        return; // agar stack hi empty hogya toh kuch ni kar sakte
    }

    int topNode = s.top();
    s.pop();
    // Reverse Stack
    // ek ek kar karke maine nikal liye saari elments then last element ko topNode mankar push krdiya, aise krke mai har ek element ko deta jaunga, or vo dusra function unko insert at bottom krta rhega reverse order mein 10 ko dalega then 20 ko bottom mein dalega and so on
    reverseStack(s);
    // insert at bottom target ko
    insertAtBottom(s , topNode);
}



int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
        cout<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}











