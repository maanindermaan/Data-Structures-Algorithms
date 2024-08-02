#include <iostream>
#include <vector> // Add the vector header

using namespace std;

void heapify(vector<int>& arr, int n, int i) // Pass vector by reference
{
    int index = i;
    int leftIndex = 2 * i + 1; // Correct the index calculations
    int rightIndex = 2 * i + 2;
    int largest = index;

    if (leftIndex < n && arr[largest] < arr[leftIndex]) // Fix the conditions
    {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[largest] < arr[rightIndex]) // Fix the conditions
    {
        largest = rightIndex;
    }

    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest); // Use 'largest' instead of 'index'
    }
}

void buildHeap(vector<int>& result, int n) // Pass vector by reference
{
    for (int i = n / 2; i >= 0; i--) // Fix the loop condition
    {
        heapify(result, n, i);
    }
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(4);
    arr1.push_back(6);
    arr1.push_back(6);
    arr1.push_back(8);

    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(5);
    arr2.push_back(7);
    arr2.push_back(9);

    int m = arr1.size();
    int n = arr2.size();

    // Concatinating vectors
    vector<int> result(arr1.begin(), arr1.end());
    result.insert(result.end(), arr2.begin(), arr2.end());

    cout << "Concatenated vector: ";
    for (int i = 0; i < m + n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    int size = result.size();

    buildHeap(result, size);

    cout << "printing the heap " << endl;
    for (int i = 0; i < size; i++) // Start from index 0
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
