// Any number can be converted to a palindrome by adding it to thereverse of the same number. For few numbers, it happens in a single iteration for few numbers the same process needs to be performed multiple times with the result of the addition For example,
// If we take 47, reverse and add, 47 + 74 = 121, which is a palindrome. Not all numbers produce palindromes so quickly such as 349
// 349 ÷ 943 = 1292
// 1292 + 2921 = 4213
// 4213+3124= 7337 ie, 349 took three iterations to arrive at a palindrome.

#include <iostream>
using namespace std;

bool isPalindrome(int num)
{
    int original = num;
    int reversed = 0;

    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

// bool isPalindrome(int num) {
//     int original = num;
//     int reversed = 0;

//     while (original != 0) {
//         int digit = original % 10;
//         reversed = reversed * 10 + digit;
//         original /= 10;
//     }

//     return num == reversed;
// }

int palindrome(int num)
{
    int result = 0;

    while (true)
    {
        int reversed = 0;
        int temp = num;

        while (temp != 0)
        {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        int sum = num + reversed;

        if (isPalindrome(sum))
        {
            result = sum;
            break;
        }

        num = sum;
    }

    return result;
}

int main()
{
    int N;
    cin >> N;

    int result = palindrome(N);
    cout << result << endl;

    return 0;
}
