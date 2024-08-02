// Ques -> You are given an array of size n. Your task is to find the number of pairs vec[i] and vec[j]  such that sun of pair is a power of 2 , where I<j

// Sol
#include <iostream>
#include <cmath>
#include <unordered_map>

int countingPowerPairs(int n, int vec[])
{
    int count = 0;
    std::unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = vec[i] + vec[j];
            int logValue = log2(sum);

            // Check if the sum is a power of 2
            if ((1 << logValue) == sum)
            {
                count++;
            }
        }
        freq[vec[i]]++;
    }

    return count;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int vec[n]; // Declare an array of size n

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

    int result = countingPowerPairs(n, vec);

    std::cout << "Count of pairs with a sum that is a power of 2: " << result << std::endl;

    return 0;
}
