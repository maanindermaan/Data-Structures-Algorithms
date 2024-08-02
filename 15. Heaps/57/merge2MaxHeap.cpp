// // APPROACH - 1
// #include <iostream>
// using namespace std;

// void heapify(int arr[], int n, int i)
// {
//     int index = i;
//     int leftIndex = 2 * i;
//     int rightIndex = 2 * i + 1;
//     int largest = index;

//     if (leftIndex <= n && arr[largest] < arr[leftIndex])
//     {
//         largest = leftIndex;
//     }
//     if (rightIndex <= n && arr[largest] < arr[rightIndex])
//     {
//         largest = rightIndex;
//     }

//     if (index != largest)
//     {
//         swap(arr[index], arr[largest]);
//         index = largest;
//         heapify(arr, n, index);
//     }
// }

// void buildHeap(int arr[], int n)
// {
//     for (int i = n / 2; i >= 1; i--) // Fix the loop condition here
//     {
//         heapify(arr, n, i);
//     }
// }

// #include <iostream>
// using namespace std;

// void mergeArrays(int arr1[], int m, int arr2[], int n, int result[])
// {
//     int i = 0; // Pointer for arr1
//     int j = 0; // Pointer for arr2
//     int k = 0; // Pointer for result

//     bool isNegativeOneInserted = false;

//     while (i < m && j < n)
//     {
//         if (arr1[i] <= arr2[j])
//         {
//             if (!isNegativeOneInserted && arr1[i] == -1)
//             {
//                 result[k] = arr1[i];
//                 isNegativeOneInserted = true;
//             }
//             else if (arr1[i] != -1)
//             {
//                 result[k] = arr1[i];
//             }
//             i++;
//         }
//         else
//         {
//             if (!isNegativeOneInserted && arr2[j] == -1)
//             {
//                 result[k] = arr2[j];
//                 isNegativeOneInserted = true;
//             }
//             else if (arr2[j] != -1)
//             {
//                 result[k] = arr2[j];
//             }
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of arr1, if any
//     while (i < m)
//     {
//         if (!isNegativeOneInserted && arr1[i] == -1)
//         {
//             result[k] = arr1[i];
//             isNegativeOneInserted = true;
//         }
//         else if (arr1[i] != -1)
//         {
//             result[k] = arr1[i];
//         }
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of arr2, if any
//     while (j < n)
//     {
//         if (!isNegativeOneInserted && arr2[j] == -1)
//         {
//             result[k] = arr2[j];
//             isNegativeOneInserted = true;
//         }
//         else if (arr2[j] != -1)
//         {
//             result[k] = arr2[j];
//         }
//         j++;
//         k++;
//     }
// }


// int main()
// {
//     int arr1[] = {-1, 1, 2, 4, 6, 8, 10};
//     int arr2[] = {-1, 1, 3, 5, 7, 9};
//     int m = sizeof(arr1) / sizeof(arr1[0]);
//     int n = sizeof(arr2) / sizeof(arr2[0]);

//     int result[m + n];
//     mergeArrays(arr1, m, arr2, n, result);

//     cout << "Merged Array: ";
//     for (int i = 0; i < m + n; i++)
//     {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     int size = m + n - 1;

//     buildHeap(result, size);

//     cout << "printing the heap " << endl;
//     for (int i = 1; i <= size; i++) // Start from index 1
//     {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



