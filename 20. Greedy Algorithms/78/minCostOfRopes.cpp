// #include <iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// int main() {
//   int arr[] = {4,3,2,6};
//   int n = 4;

//   priority_queue<int, vector<int>, greater<int> > pq;
//   for(int i=0; i<n; i++) {
//     pq.push(arr[i]);
//   }
//   int cost = 0;
//   while(pq.size() != 1) {
//     int first = pq.top();
//     pq.pop();
//     int second = pq.top();
//     pq.pop();

//     cost += first + second;
//     int newLength = first + second;
//     pq.push(newLength);

//   }
//   cout << "Cost is: " << cost << endl;
//   return 0;
// }

// practice
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
  int arr[] = {4, 3, 2, 6};
  int n = 4;

  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < 4; i++)
  {
    minHeap.push(arr[i]);
  }

  int sum = 0;

  while (minHeap.size() != 1)
  {
    int top1 = minHeap.top();
    minHeap.pop();

    int top2 = minHeap.top();
    minHeap.pop();

    sum += top1 + top2;
    int newSum = top1 + top2;

    minHeap.push(newSum);
  }
  cout<<sum;
  return 0;
}