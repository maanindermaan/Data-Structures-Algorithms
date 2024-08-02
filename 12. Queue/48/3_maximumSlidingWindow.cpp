#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums , int k){

    // 1. Queue create
    deque<int>dq;
    vector<int>ans;

    // 2. Traversing first Window
    for(int i=0 ;i <k ; i++){
        // chote element remove krdo piche se
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // inserting index, so that we can check out of window element
        dq.push_back(i);
    }
    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // 3. remaining windows ko process krdo
    for(int i = k ; i<nums.size(); i++){
        // out of window element ko remove krdiya
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        // ab firse current element ke liye chote element ko remove krna hai
         while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // inserting index, so that we can check out of window element
        dq.push_back(i);

        // current window ka ans store krna haii
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {

//     // 1. Queue create
//     deque<int> dq;
//     vector<int> ans;

//     // 2. Traversing first Window
//     for (int i = 0; i < k; i++)
//     {
//         // chote element remove krdo piche se
//         while (!dq.empty() && nums[i] >= nums[dq.back()])
//         {
//             dq.pop_back();
//         }
//         // inserting index, so that we can check out of window element
//         dq.push_back(i);
//     }
//     // store answer for first window
//     ans.push_back(nums[dq.front()]);

//     // 3. remaining windows ko process krdo
//     for (int i = k; i < nums.size(); i++)
//     {
//         // out of window element ko remove krdiya
//         if (!dq.empty() && i - dq.front() >= k)
//         {
//             dq.pop_front(); // pop_front() isliye kiya kyunki mai queue mai push_back krrha hu. top sabse pehle queue ke aage aaya hooga thats why
//             // Out of bound to aage se remove hoga or piche se add hoga
//         }

//         // ab firse current element ke liye chote element ko remove krna hai
//         while (!dq.empty() && nums[i] >= nums[dq.back()])
//         {
//             dq.pop_back();
//         }
//         // inserting index, so that we can check out of window element
//         dq.push_back(i);

//         // current window ka ans store krna haii
//         ans.push_back(nums[dq.front()]);
//     }

//     return ans;
// }



int main(){
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums , k);
    
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    
return 0;
}


// Approach 2  -> Single Traversal
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
