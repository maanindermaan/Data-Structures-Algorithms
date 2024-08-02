#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

pair<int , int> absoluteTargetValue(vector<int> &arr, int target)
{
    int i = 0;
    int j = 1;
    int diff = 0;
    int closest = arr[1] - arr[0];
    int ansi = 0;
    int ansj = 0;
    

    while (i < j && j < arr.size())
    {
        diff = arr[j] - arr[i];

        if (diff < target)
        {
            j++;
        }

        else if (diff > target)
        {
            i++;
        }

        if (abs(target - diff) < abs(target - closest))
        {
            closest = diff;
            ansi = arr[i];
            ansj = arr[j];
        }
    }
    return {ansi , ansj};
}

int main()
{
    vector<int> arr{10, 12, 14, 15, 20};
    int target = 7;

    pair<int , int> ans = absoluteTargetValue(arr, target);

    cout<<ans.first<<" , "<<ans.second;
    return 0;
}