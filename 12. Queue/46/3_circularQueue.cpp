#include <iostream>
using namespace std;

class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data) {
        //Queue Full

        //single element case - > first element

        //circular nature

        //normal flow
        //TODO: add one more condition in the QUEUE FULL if block
        if((front == 0 && rear == size-1)) {
            cout << "Q is fulll, cannot insert" << endl;
        }
        else if(front == rear+1 && rear == front-1){
            cout << "Q is fulll, cannot insert" << endl;
        }
        else if(front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0 ) {
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear]= data;
        } 
    }

    void pop() {
        //empty check
        //single element
        //circular nature
        //normal flow
        if(front == -1) {
            cout << "Q is empty , cannot pop" << endl;
        }
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;  
        }
        else if(front == size-1) {
            front = 0;
        }
        else {
            front++;
        }
    }

};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}















#include <iostream>
#include <queue>
using namespace std;

class circularQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    circularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // 1. Queue Full
        if (rear == size - 1 && front == 0)
        {
            cout << "Queue is full";
        }
        else if (front == rear + 1 && rear == front - 1)
        {
            cout << "Q is fulll, cannot insert" << endl;
        }
        


        // 2. Single Element to insert 
        if(front ==-1){
            front = rear = 0;
            arr[rear] = data;
        }


        // 3. Circular Nature
        else if (rear = size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }


        // 4. Default Case
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // 1. Empty Check
        if (front == -1)
        {
            cout << "Queue is empty";
        }

        // 2.Single Element Pop
        else if(front == rear && front != -1){
            arr[front] = -1;
            front == rear == -1;
        }


        // 3. Circular Nature
        else if(front == size-1){
            front = 0;
        }

        // 4. Normal Flow
        else{
            front++;
        }
    }
};

int main()
{

    return 0;
}