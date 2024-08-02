#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
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

int main()
{
    int arr[] = {5, 6, 7, 8, 1, 2, 3, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int index = binarySearch(arr, size, key);

    if (index != -1)
        cout << "Key found at index " << index << " i.e. " << arr[index] << endl;
    else
        cout << "Key not found." << endl;

    return 0;
}
