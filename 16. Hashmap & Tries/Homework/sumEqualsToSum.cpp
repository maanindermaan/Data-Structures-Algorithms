#include <iostream>
using namespace std;

int findPairs(int arr[], int n)
{
    // 1. Create a unordered map
    unordered_map<int, bool> mapping; //{sum , bool(T/F)}

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 2. Store the key pair and correspoding sum as well
            int sum = arr[i] + arr[j];
            // 3. Kya aisa koi sum pehle se pada tha
            if (mapping.find(sum) != mapping.end())
            {
                return 1;
            }
            else
            {
                mapping[sum] = true;
            }
        }
    }
    return 0;
}

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    cout << findPairs(arr, n);
    return 0;
}