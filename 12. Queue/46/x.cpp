
#include <iostream>
#include <queue>
using namespace std;

class deques
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    deques(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
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
        else if (rear == size-1 && front != 0)
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



    void pushFront(int data)
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
            arr[front] = data;
        }


        // 3. Circular Nature
        else if (front == 0 && rear != size-1)
        {
            front = size-1;
            arr[front] = data;
        }


        // 4. Default Case
        else{
            front--;
            arr[front] = data;
        }
    }

    void popFront()
    {
        // 1. Empty Check
        if (front == -1)
        {
            cout << "Queue is empty";
        }

        // 2.Single Element Pop
        else if(front == rear && front != -1){
            arr[front] = -1;
            front = rear = -1;
        }


        // 3. Circular Nature
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }

        // 4. Normal Flow
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popRear()
    {
        // 1. Empty Check
        if (front == -1)
        {
            cout << "Queue is empty";
        }

        // 2.Single Element Pop
        else if(front == rear && front != -1){
            arr[front] = -1;
            front = rear = -1;
        }


        // 3. Circular Nature
        else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }

        // 4. Normal Flow
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    void print() {
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
  deques dq(10);
  dq.print();

  cout<<"push rear : ";
  dq.pushRear(10);
  dq.print();
  

  cout<<"push rear : ";
  dq.pushRear(20);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(30);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(40);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(50);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(60);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(70);
  dq.print();
  cout<<"push rear : ";
  dq.pushRear(80);
  dq.print();

  cout<<"pop rear : ";
  dq.popRear();
  dq.print();

  cout<<"pop rear : ";
  dq.popRear();
  dq.print();

  cout<<"pop front : ";
  dq.popFront();
  dq.print();

  cout<<"pop front : ";
  dq.popFront();
  dq.print();

  cout<<"pop front : ";
  dq.popFront();
  dq.print();

  cout<<"push front : ";
  dq.pushFront(101);
  dq.print();

  cout<<"push front : ";
  dq.pushFront(102);
  dq.print();

  cout<<"push front : ";
  dq.pushFront(103);
  dq.print();

  cout<<"push front : ";
  dq.pushFront(104);
  dq.print();

  cout<<"pop front : ";
  dq.popFront();
  dq.print();

  cout<<"pop front : ";
  dq.popFront();
  dq.print();

  cout<<"push rear : ";
  dq.pushRear(201);
  dq.print();

  cout<<"push rear : ";
    dq.pushRear(202);
  dq.print();

  cout<<"push rear : ";
    dq.pushRear(203);
  dq.print();
  cout<<"push rear : ";
    dq.pushRear(204);
  dq.print();

  cout<<"push rear : ";
    dq.pushRear(205);
  dq.print();


  return 0;
}