#include <iostream>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    // jiski value kamm hogi  uske adhar pe sort krdo
    return a.first < b.first;
}
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> data;
    vector<int> ans;

    // pair inserted inside vector
    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        int index = i;
        data.push_back({val, index});
    }

    // now sort it
    sort(data.begin(), data.end(), cmp);

    int start = 0;
    int end = data.size() - 1;
    while (start < end)
    {
        if (data[start].first + data[end].first == target)
        {
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if (data[start].first + data[end].first > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}



// // practice
// #include <iostream>
// using namespace std;

// static bool cmp(pair<int, int> a, pair<int, int> b)
// {
//     return a.first < b.first;
// }
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     vector<pair<int , int>> data; //{data , index}
//     vector<int> ans;

//     for(int i=0 ; i<nums.size() ; i++){
//         int value = nums[i];
//         int index = i;
//         data.push_back({value , index});
//     }

//     sort(data.begin() , data.end());

//     int start = 0;
//     int end = data.size()-1;

//     while(start < end){
//         if(data[start].first + data[end].first == target){
//             ans.push_back(data[start].second);
//             ans.push_back(data[end].second);
//             break;
//         }
//         else if(data[start].first + data[end].first > target){
//             end--;
//         }
//         else{
//             start++;
//         }
//     }

//     return ans;
// }

// int main()
// {
//     vector<int> nums{2, 7, 11, 15};
//     int target = 9;

//     vector<int> ans = twoSum(nums, target);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }
