// You are given a binary array consisting of only 0's and 1's, and an integer K. The goal is to find the
// maximum number of consecutive 1's that can be obtained by having at most K 0's in window

#include <iostream>
using namespace std;

int maximumConsecutiveOnes(vector<int> &arr, int k)
{
    int i = 0;
    int j = 0;
    int zeroCount = 0;
    int consequtiveOnesCount = 0;

    while (j < arr.size())
    {
        while (zeroCount < 3)
        {
            if (arr[i] == 0)
            {
                zeroCount++;
            }
            if (arr[i] == 1)
            {
                consequtiveOnesCount++;
            }
        }
    }
}

int main()
{
    vector<int> arr{0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0};

    int k = 2;

    maximumConsecutiveOnes(arr, k);
    return 0;
}