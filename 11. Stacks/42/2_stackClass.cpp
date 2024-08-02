#include <iostream>
using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size]; // pointer ko memory allocate krwadi
        this->size = size;
        top = -1; // empty case. 0 is valid index
    }

    // functions :

    void push(int data)
    {
        if ((size - top) > 1)
        {
            // space available
            // insert
            top++;
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "Stack Overflow";
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // stacks is empty
            cout << "Stack Underflow";
        }
        else
        {
            // stacks is not empty
            top--;
        }
    }

    int getTop()
    {
        // stacks is empty
        if (top == -1)
        {
            cout << "No element to insert";
        }
        // stacks is not empty
        else
        {
            return arr[top];
        }
    }

    // Returns number of valid elements present in stack
    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // CREATION
    Stack s(5);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);stack overflow

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Size of stack " << s.getSize() << endl;

    s.pop(); // stack underflow
    return 0;
}