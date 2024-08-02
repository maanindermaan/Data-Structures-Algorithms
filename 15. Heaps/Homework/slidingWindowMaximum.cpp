#include <iostream>
#include <queue>
using namespace std;

vector<int> maximumSlidingWindow(vector<int> &nums, int k)
{
    // 1. Create a prioirty Queue
    priority_queue<pair<int, int>> maxHeap; // pair(vector->data   ,    index);

    // 2. Insert first k elements into pq
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(make_pair(nums[i], i));
    }

    // 3. Push maximum into answer
    vector<int> ans;
    pair<int, int> temp = maxHeap.top();
    ans.push_back(temp.first);

    // 4. Move the window, Push the upcoming elments and hence remove the elments that is greater and is coming on top
    for (int i = k; i < nums.size(); i++)
    {
        maxHeap.push(make_pair(nums[i], i));

        // 5. Check for out of bound
        if (maxHeap.top().second <= i - k)
        {
            maxHeap.pop();
        }

        // 6. Push maximum into ans
        pair<int, int> newElement = maxHeap.top();
        ans.push_back(newElement.first);

    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);

    int k = 3;

    vector<int> ans = maximumSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}