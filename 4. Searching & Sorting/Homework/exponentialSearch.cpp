#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] <= arr[end])
        {
            // Right Subarray
            if (key > arr[mid] && key <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            // Left Subaaray
            if (key >= arr[start] && key < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}




int binarySearch2(int arr[], int size, int key, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return -1;
}











int exponentialSearch(int arr[], int size, int key)
{
    if (arr[0] == key)
    {
        return 0;
    }
    int i = 1;
    while (i < size && arr[i] <= key)
    {
        i = i * 2;
    }
    int startIndex = i / 2;
    int endIndex = min(i, size - 1);
    int ans = binarySearch2(arr, size, key, startIndex, endIndex);
    return ans;
}

int main()
{
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int ans = exponentialSearch(arr, size, key);
    cout << ans;

    return 0;
}