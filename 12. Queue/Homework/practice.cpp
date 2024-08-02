#include <iostream>
using namespace std;

class kQueue
{
public:
    int k, n, freespot; 
    int *arr;
    int *front;
    int *rear;
    int *next;

    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
            if (i == n - 1)
            {
                next[i] = -1;
            }
        }
    }

    // Push x into qith queue
    bool push(int x, int qi)
    {
        if(freespot == -1){
            cout<<"Queue Overflow can't insert more";
            return false;
        }

        // 1. give index
        int index = freespot; 

        // 2. update freespot
        freespot = next[index];

        // 3. Check whether it's first element in queue or not
        if(front[qi] == -1){
            front[qi] = index;
        }
        else{
            next[rear[qi]] = index;
        }

        // 4. Update next
        next[index] = -1;

        // 5. Update rear 
        rear[qi] = index;

        // 6. insert element
        arr[index] = x;

        return true;
    }

    int pop(int qi){
        if(front[qi] == -1){
            cout<<"QUEUE Is empty"<<endl;
            return -1;
        }

        // find next index
        int index = front[qi];

        front[qi] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }

    void printQueue(int qi)
    {
        if (front[qi] == -1)
        {
            cout << "Queue " << qi << " is empty" << endl;
            return;
        }

        int index = front[qi];
        while (index != -1)
        {
            cout << arr[index] << " ";
            index = next[index];
        }
        cout << endl;
    }
};

int main()
{
    kQueue k(6 , 2);
    k.push(10 , 0);
    k.push(20 , 0);
    k.push(30 , 1);
    k.push(40 , 0);
    k.push(50 , 1);
    k.push(60 , 1);

    cout << "Queue 0: ";
    k.printQueue(0);

    cout << "Queue 1: ";
    k.printQueue(1);

    k.pop(0);
    k.pop(1);

     cout << "Queue 0: ";
    k.printQueue(0);

    cout << "Queue 1: ";
    k.printQueue(1);

    return 0;
}
