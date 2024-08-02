#include <iostream>
#include <queue>
using namespace std;

void callMedian(int &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element){
    // 1. Cases that exist to find median
    // case 1.1 : size of both the heaps are equal {size , size}
    if(minHeap.size() == maxHeap.size()){
        // 2. Cases that exists wile insertion
        // case 1.2 : if element is greater than median -> insert into MINHEAP(RIGHT)
        if(element > median){
            minHeap.push(element);
            // Tab median kya hota it is case { size , size+1}
            median = minHeap.top();
        }
        // if element is smaller than median -> insert into MAXHEAP (LEFT)
        else{
            maxHeap.push(element);
            // Tab median kya hota it is case { size+1 , size}
            median = maxHeap.top();
        }
    }

    // case 2.1 : size of min Heap is more // {size , size+1}
    else if(minHeap.size() > maxHeap.size()){
        // case 2.2 : if element is greater than median -> insert into MINHEAP(RIGHT)
        if(element > median){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp); // {size+1 , size}
            minHeap.push(element); // {size+1 , size+1}; -> we can find median now
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        // if element is smaller than median -> insert into MAXHEAP (LEFT)
        else{
            // insert to left(MAX HEAP)
            maxHeap.push(element); // {size+1 , size+1}
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }

    // case 3.1 : size of max Heap is more {size+1 , size}
    else{
        // else if(minHeap.size() < maxHeap.size())
        // case 2.2 : if element is greater than median -> insert into MINHEAP(RIGHT)
        if(element > median){
            // inseet into minHeap
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else{
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp); // {size , size+1}
            maxHeap.push(element); // {size+1 , size+1}; -> we can find median now
            median = (minHeap.top() + maxHeap.top()) / 2;

        }

    }

}

int main()
{
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout << "->  " << median << " ";
    }
    cout << endl;

    return 0;
}

// USING SWITCH CASES
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int signum(int a, int b)
// {
//     if (a == b)
//         return 0;
//     if (a > b)
//         return 1;
//     if (a < b)
//         return -1;
// }

// void callMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
// {

//     switch (signum(minHeap.size(), maxHeap.size()))
//     {
//     case 0:
//         if (element > median)
//         {
//             minHeap.push(element);
//             median = minHeap.top();
//         }
//         else
//         {
//             maxHeap.push(element);
//             median = maxHeap.top();
//         }
//         break;
//     case 1:
//         if (element > median)
//         {
//             int minTop = minHeap.top();
//             minHeap.pop();
//             maxHeap.push(minTop);
//             minHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2.0;
//         }
//         else
//         {
//             maxHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2.0;
//         }
//         break;
//     case -1:
//         if (element > median)
//         {
//             minHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2.0;
//         }
//         else
//         {
//             int maxTop = maxHeap.top();
//             maxHeap.pop();
//             minHeap.push(maxTop);
//             maxHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2.0;
//         }
//         break;
//     }
// }

// int main()
// {
//     int arr[12] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
//     int n = 12;

//     // 5 6 5 6 5 6
//     double median = 0;
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     for (int i = 0; i < n; i++)
//     {
//         int element = arr[i];
//         callMedian(median, maxHeap, minHeap, element);
//         cout << "arr[i]->median:  " << median << endl;
//     }
//     cout << endl;

//     return 0;
// }