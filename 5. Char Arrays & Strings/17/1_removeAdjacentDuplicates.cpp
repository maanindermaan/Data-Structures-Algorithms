#include <iostream>
using namespace std;

// 1. Babbar Method
string removeDuplicates(string s)
{
    string ans = "";
    ans.push_back(s[0]);
    int i = 1;

    while (i < s.length())
    {
        cout << "i value :" << i << endl;
        cout << ans.length() << endl;
        if ((ans.length() - 1 >= 0) && ans[ans.length() - 1] == s[i])
        {
            cout << ans[ans.length() - 1] << " Matching -> " << s[i] << endl;
            ans.pop_back();
            cout << "ans after popping " << ans << endl;
        }
        else
        {
            cout << "Pushing into ans -> " << s[i] << endl;
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

// 2. Map method -> Partially correct
// string removeDuplicates(string s) {
//         string ans = "";
//         unordered_map<char , int> mp;
//         for(int i = 0; i < s.length(); i++) {
//             mp[s[i]]++;
//         }
//         // Construct the result string without duplicates
//         for(auto& pair : mp) {
//             if(pair.second % 2 == 1){
//                 ans += pair.first;
//             }
//         }
//         return ans;
//     }

int main()
{
    string s = "azyyzy";

    string ans = removeDuplicates(s);

    cout << "Without Duplicates : ";

    cout << ans << endl;

    return 0;
}

// 3. Leetcode Solution
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans;
        if (!s.empty())
        { // Ensure s is not empty
            ans.push_back(s[0]);
            int i = 1;

            while (i < s.length())
            {
                if (!ans.empty() && ans.back() == s[i])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};




