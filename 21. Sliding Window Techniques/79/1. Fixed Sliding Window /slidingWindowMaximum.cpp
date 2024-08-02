// #include <iostream>
// #include <vector>
// #include <deque>
// using namespace std;
// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     // we will store indexes in deque
//     // taki mai pata laga pau ki jo bhi element hai vo current window mein lie karha hai ya nahi
//     deque<int> dq;
//     vector<int> ans;

//     // process first k size window
//     // element insert kro or usse(element) chote koi bhi elements hai toh use pop karwado
//     for (int i = 0; i < k; i++)
//     {
//         // agar element se koi bhi chota exist krte hai deque mein to pop kardo
//         // isse karne se pehle pe hmesha bigger element hi rhega
//         while (!dq.empty() && nums[dq.back()] < nums[i]){
//             dq.pop_back();
//         }
//         // insert current element
//         dq.push_back(i);
//     }

//     // isse karne se pehle pe hmesha bigger element hi rhega
//     // ans store karlo for 1st window
//     ans.push_back(nums[dq.front()]);

//     // remaining windows
//     for (int i = k; i < nums.size(); i++)
//     {
//         // removal
//         // jab window 123 se 234 pe pochi toh 1 wala delete krdia i = 4 here and k = 3. i-k = 1 
//         // and if 1>=dq.front() to remove krdo becuase front mein toh mujhe maximum chahiye
//         if (!dq.empty() && i - k >= dq.front())
//             dq.pop_front();

//         // additional
//         while (!dq.empty() && nums[dq.back()] < nums[i])
//             dq.pop_back();
//         // insert element
//         dq.push_back(i);

//         /// ans store
//         ans.push_back(nums[dq.front()]);
//     }
//     return ans;
// }

// int main()
// {

//     vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
//     int k = 3;

//     vector<int> ans = maxSlidingWindow(nums, k);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }




// practice
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int>dq;
    vector<int>ans;

    // inserting first k elemnts's indexes into dq
    for(int i=0 ; i<k ; i++){
        // removing or popping condition because we want bigger at top
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        // else insert that index
        dq.push_back(i);
    }

    // calculate ans for first k size window
    // because we have maintained a decreasing order
    ans.push_back(nums[dq.front()]);

    // for remaining left out windows
    for(int i=k ; i<nums.size() ; i++){
        // remove out of bound elements
        if(!dq.empty() && i-k >= dq.front()){
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        // else insert that index
        dq.push_back(i);

        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main()
{

    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
