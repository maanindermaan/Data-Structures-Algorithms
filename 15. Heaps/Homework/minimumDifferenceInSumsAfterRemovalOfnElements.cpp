#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int mimimumDifference(vector<int> &nums)
{
    int n = nums.size() / 3;
    vector<int> prefix(nums.size(), -1), suffix(nums.size(), -1);
    // prefix[i] = sum of first n elements from left side;
    // suffix[i] = sum of first n elements from right side;

    int minSum = 0; // minimum n elements sum
    // Creating a maxHeap
    priority_queue<int> maxHeap;

    // inserting into max heap for minimum Sum First 2 element nikalo jo sum ko minimize krenge
    for (int i = 0; i < nums.size(); i++)
    {
        minSum += nums[i];
        maxHeap.push(nums[i]);

        // Pop out maximum elment if it is out of bound
        if (maxHeap.size() > n)
        {
            minSum -= maxHeap.top();
            maxHeap.pop();
        }

        // If size of maxheap is equal to n then push it to prefix
        if (maxHeap.size() == n)
        {
            prefix[i] = minSum;
        }
    }

    int maxSum = 0; // maximum n elements sum
    // creating a minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        maxSum += nums[i];
        minHeap.push(nums[i]);

        // Pop out maximum elment if it is out of bound
        if (minHeap.size() > n)
        {
            maxSum -= minHeap.top();
            minHeap.pop();
        }

        // If size of maxheap is equal to n then push it to prefix
        if (minHeap.size() == n)
        {
            suffix[i] = maxSum;
        }
    }

    int ans = INT_MAX;

    for (int i = n - 1; i < 2 * n; i++)
    {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }

    return ans;
}

// int mimimumDifference(vector<int> &nums)
// {
//     // 1. Create 2 arrays prefix for storing min sum and suffix for maximum sum
//     vector<int> suffix , prefix;

//     int n = nums.size()/2;

//     int minAns = 0;

//     // 2. Create a maxHeap for minimum Sum. Because we are removing maximum element from top
//     priority_queue<int> maxHeap;

//     for(int i=0 ; i<nums.size() ; i++){
//         // 3. Push elements into maxHeap
//         int element = nums[i];
//         minAns += element;
//         maxHeap.push(element);

//         // 4. Check whether the top element is out of bound or not
//         if(maxHeap.size() > n){
//             minAns -= maxHeap.top();
//             maxHeap.pop();
//         }

//         // 5. If not then push into prefix array
//         if(maxHeap.size() == n){
//             prefix[i] = (minAns);
//         }
//     }

//     int maxAns = 0;

//     // 6. Create a maxHeap for minimum Sum. Because we are removing maximum element from top
//     priority_queue<int , vector<int> , greater<int>> minHeap;

//     for(int i=nums.size()-1 ; i>=0 ; i--){
//         // 7. Push elements into maxHeap
//         int element = nums[i];
//         maxAns += element;
//         minHeap.push(element);

//         // 9. Check whether the top element is out of bound or not
//         if(minHeap.size() > n){
//             maxAns -= minHeap.top();
//             minHeap.pop();
//         }

//         // 10. If not then push into suffix array
//         if(minHeap.size() == n){
//             suffix[i] = (maxAns);
//         }
//     }

//     int ans = INT_MAX;

//     for (int i = n - 1; i < 2 * n; i++)
//     {
//         ans = min(ans, prefix[i] - suffix[i + 1]);
//     }

//     return ans;
// }

int main()
{
    vector<int> nums{7, 9, 5, 8, 1, 3};
    cout << mimimumDifference(nums);
    return 0;
}