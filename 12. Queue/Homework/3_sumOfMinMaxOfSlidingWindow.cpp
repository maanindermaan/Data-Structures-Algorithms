#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int minMaxSlidingWindow(vector<int> &nums, int k)
{
    // 1. Queue create and ans array create
    deque<int> dq1, dq2; // dq1->MAXIMUM     dq2->MINIMUM
    int ans=0;             // because mujhe sum chiye na min max ka

    // 2. Process first k elements
    for (int i = 0; i < k; i++)
    {

        // 2.1 remove smaller element - FOR MAX
        while (!dq1.empty() && nums[i] >= nums[dq1.back()])
        {
            dq1.pop_back();
        }

        // 2.2 remove bigger element - FOR MIN
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }

    // Calculating answer
    ans += nums[dq1.front()] + nums[dq2.front()];

    // 3. Reamaining k elements
    for (int i = k; i < nums.size(); i++)
    {
        // 3.1 removing extra front side elements out of bound of dq1
        while (!dq1.empty() && i - dq1.front() >= k)
        {
            dq1.pop_front();
        }

        // 3.2 removing extra front side elements out of bound of dq2
        while (!dq2.empty() && i - dq2.front() >= k)
        {
            dq2.pop_front();
        }

        // 3.3 Otherwise now check for greater element in queue if not present pop till empty or till
        //     larger element arrives and then push it
        while (!dq1.empty() && nums[i] >= nums[dq1.back()])
        {
            dq1.pop_back();
        }

        // 3.4 Otherwise now check for smaller element in queue if not present pop till empty or till
        //     smaller element arrives and then push it
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        dq1.push_back(i);
        dq2.push_back(i);

        ans += nums[dq1.front()] + nums[dq2.front()];
    }

    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(-3);
    nums.push_back(-1);
    nums.push_back(-2);
    int k = 4;
    int ans = minMaxSlidingWindow(nums, k);
    cout << endl;

    cout << ans;

    cout << endl;
    cout << endl;

    return 0;
}



// Approach 2
#include <iostream> 
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    deque<int> dq1, dq2;
    long long sum = 0;

    // Process each element in the array
    for (int i = 0; i < n; i++) {
        // Remove elements out of the current window for max deque
        while (!dq1.empty() && dq1.front() <= i - k) {
            dq1.pop_front();
        }

        // Remove smaller elements as they are not useful for max deque
        while (!dq1.empty() && nums[i] >= nums[dq1.back()]) {
            dq1.pop_back();
        }

        // Remove elements out of the current window for min deque
        while (!dq2.empty() && dq2.front() <= i - k) {
            dq2.pop_front();
        }

        // Remove larger elements as they are not useful for min deque
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        // Add current element at the back of both deques
        dq1.push_back(i);
        dq2.push_back(i);

        // If the window is fully within the array, add the maximum and minimum
        if (i >= k - 1) {
            sum += nums[dq1.front()] + nums[dq2.front()];
        }
    }

    return sum;
}