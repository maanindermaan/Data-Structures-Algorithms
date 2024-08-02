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
        // 1. Oveflow
        if (freespot == -1)
        {
            return false;
        }

        // 2. Find first free index
        int index = freespot;

        // 3. update free spot
        freespot = next[index];

        // 4. Check for first element of qi
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        // 4.2 Else Link new element to that Q's rearest element
        else
        {
            next[rear[qi]] = index;
        }

        // 5. Update next
        next[index] = -1;

        // 6. Update rear
        rear[qi] = index;

        // 7. Add data finally
        arr[index] = x;
        return true;
    }

    // Pop element from qith queue
    int pop(int qi)
    {
        // 1. Undeflow
        if (front[qi] == -1)
        {
            return -1;
        }

        // 2. Find index to pop()
        int index = front[qi];

        // 3. front update
        front[qi] = next[index];

        // 4. Update freespots
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    bool push(int element, int qi)
    {
        // 1. Check for overflow condition
        if (freespot == -1)
        {
            return false;
        }

        // 2. Find index to insert
        // we can only insert at freespot
        int index = freespot;

        // 3. Update freespot
        // Now next freespot will be at next[index]. Because at this index we have inserted some value
        // and next value can be inserted at next index only. And initally queue is empty so
        // next index wil be empty and can be treated as empty queue
        freespot = next[index];

        // 4. check for front or rear
        // e.g. we are talking about qi = 0. front[0] = -1, which means front is empty. So now we take front to index
        if(front[qi] == -1){
            front[qi] = index; 
        }
        // creating linkage for new element to queue's rear element
        else{
            next[rear[qi]] = index;
        }

        // 5. update next
        // we are currently inserting at index. So we can't say that what will be at index's next because 
        // currently we are inserting at index only.
        next[index] = -1;

        // 6. update rear
        rear[qi] = index;
        arr[index] = element;
        return true;
    }
};

int main()
{

    return 0;
}