#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> targetSum(vector<int> &arr, int target)
{
    sort(arr.begin() , arr.end());

    int i = 0;
    int j = arr.size()-1;

    vector<pair<int, int>> ans;

    while(i<j && j<arr.size()){
        if(arr[i] + arr[j] == target){
            ans.push_back({arr[i],arr[j]});
            i++;
            j--;
        }

        else if(arr[i] + arr[j] < target){
            i++;
        }

        else{
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{10, 9, 5, 12, 6, 13};
    int target = 22;

    vector<pair<int, int>>ans = targetSum(arr, target);

    for(auto i : ans){
        cout<<"("<<i.first<<","<<i.second<<")";
        cout<<endl;
    }
    return 0;
}