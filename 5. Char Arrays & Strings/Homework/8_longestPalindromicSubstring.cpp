#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void longestPalindromeSubstring(string s)
{
    string ans = " ";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1); // substring takes start value and length
                if (t.size() > ans.size())
                { // checking for longest palindromic substring
                    ans = t;
                }
            }
        }
    }
    cout << ans;
}

int main()
{
    string s = "babab";
    longestPalindromeSubstring(s);
    return 0;
}

// Method - 2 -> O(n^3) T.C.
class Solution
{
public:
    bool checkPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1; // Corrected j to start from the last index

        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        vector<string> ans;
        ans.push_back("");

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (checkPalindrome(s.substr(i, j - i + 1)) && s.substr(i, j - i + 1).size() > ans[0].size())
                {
                    ans.clear();
                    ans.push_back(s.substr(i, j - i + 1));
                }
            }
        }
        return ans[0];
    }
};

// Method -3 -> More Optmisied
class Solution
{
public:
    string expandAroundIndex(string s, int i, int j)
    {
        // Jab tak match krega count increment krdo i peche le jao or j aage lejao
        while ((i >= 0) && (j < s.length()) && (s[i] == s[j]))
        {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        string maxPalindrome = "";
        string max_out_of_two = "";

        for (int i = 0; i < n; i++)
        {
            // ODD
            string oddKaAns = expandAroundIndex(s, i, i); // i and j are on same position help to increease count of element at same index
            // EVEN
            string evenKaAns = expandAroundIndex(s, i, i + 1); // i and j are adjacent to each other

            if (oddKaAns.size() > evenKaAns.size())
            {
                max_out_of_two = oddKaAns;
            }
            else
            {
                max_out_of_two = evenKaAns;
            }

            if (max_out_of_two.size() > maxPalindrome.size())
            {
                maxPalindrome = max_out_of_two;
            }
        }
        return maxPalindrome;
    }
};