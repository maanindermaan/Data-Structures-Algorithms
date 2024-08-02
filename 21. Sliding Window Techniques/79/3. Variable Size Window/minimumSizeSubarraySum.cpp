#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0; // window ke liye
    int j = 0;
    int sum = 0; // target se compare karane ke liye
    int len = INT_MAX; //

    while (j < nums.size())
    {
        // jis bhi number pe j aagya hai use sum mein include kro
        // include current number
        sum = sum + nums[j]; // or nums[i] are on same place
        // mere paas ek window ka sum ready h
        while (sum >= target)
        {
            // minimise -> sum me se decrease karo, len bhi update krelna, i/start ko aage badhana padega

            len = min(len, j - i + 1);
            sum = sum - nums[i];
            i++;
        }
        j++;
    }

    if (len == INT_MAX)
        return 0;
    else
        return len;
}

int main()
{
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;

    cout<< minSubArrayLen(target , nums);
    return 0;
}

// // practice
// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// int minSubArrayLen(int target, vector<int> &nums)
// {
//     int i = 0;
//     int j = 0;
//     int sum = 0;
//     int minLen = INT_MAX;

//     while(j<nums.size()){
//         sum = sum + nums[j];

//         while(sum >= target){
//             // find length
//             minLen = min(minLen , j-i+1);
//             sum = sum - nums[i];
//             i++;
//         }
//         j++;
//     }

//     if(minLen == INT_MAX){
//         return 0;
//     }
//     else{
//         return minLen;
//     }
// }

// int main()
// {
//     vector<int> nums{2, 3, 1, 2, 4, 3};
//     int target = 7;

//     cout << minSubArrayLen(target, nums);
//     return 0;
// }
