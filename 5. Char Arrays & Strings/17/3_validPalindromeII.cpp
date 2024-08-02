// Check whether a string is valid Palindrome or not if you remove one character
// Remove all occurances of a substring
#include <iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

bool validPalindromeII(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            // EK baari i ko remove kardo , ek baari j ko remove kardo
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else
        {
            // s[i] == s[j]
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    if (validPalindromeII(s))
    {
        cout << "Yes it is a palindrome";
    }
    else
    {
        cout << "NO ";
    }

    return 0;
}

// My approach bettter one
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        int cnt = 1;

        while (i <= j)
        {
            if (s[i] != s[j])
            {
                while (cnt--)
                {
                    if (j - 1 >= 0 && s[i] == s[j - 1])
                    {
                        j--;
                    }
                    else
                    {
                        i++;
                    }
                    continue;
                }
            }
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

// Approach 2
class Solution
{
public:
    bool checkPalindrome(string word, int i, int j)
    {
        while (i <= j)
        {
            if (word[i] != word[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return (checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1));
            }
            i++;
            j--;
        }
        return true;
    }
};