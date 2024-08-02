// Not working
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

static bool mycomp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

int findBeauty(string str, unordered_map<char, int> &freqMap, vector<pair<char, int>> &freqVec)
{
    int ans = 0;
    for (char i : str)
    {
        freqMap[i]++;
    }
    if (freqMap.size() > 1)
    {
        for (auto i : freqMap)
        {
            freqVec.push_back(i);
        }
        sort(freqVec.begin(), freqVec.end(), mycomp);

        ans = freqVec[0].second - freqVec[freqVec.size() - 1].second;
    }

    for (auto ch : freqVec)
    {
        cout << ch.first << " " << ch.second << endl;
    }

    cout << "ans -> " << ans << endl;

    return ans;
}

int expandAroundIndex(string s, int i, int j)
{
    unordered_map<char, int> freqMap;
    vector<pair<char, int>> freqVec;

    while ((i >= 0) && (j < s.length()))
    {
        i--;
        j++;
    }
    string str = s.substr(i + 1, j - i - 1);

    cout << str << endl;

    return findBeauty(str, freqMap, freqVec);
}

int main()
{
    string s = "aabcb";
    int total_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int odd = expandAroundIndex(s, i, i);
        total_count += odd;
        int even = expandAroundIndex(s, i, i + 1);
        total_count += even;
    }
    cout << total_count << endl;
    return 0;
}

// 2nd version
class Solution
{
public:
    static bool mycomp(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }

    int findBeauty(string str, unordered_map<char, int> &freqMap, vector<pair<char, int>> &freqVec)
    {
        int ans = 0;
        for (char i : str)
        {
            freqMap[i]++;
        }
        if (freqMap.size() > 1)
        {
            for (auto i : freqMap)
            {
                freqVec.push_back(i);
            }
            sort(freqVec.begin(), freqVec.end(), mycomp);

            ans = freqVec[0].second - freqVec[freqVec.size() - 1].second;
        }
        return ans;
    }

    int expandAroundIndex(string s, int i, int j)
    {
        int ans = 0;

        unordered_map<char, int> freqMap;
        vector<pair<char, int>> freqVec;

        while ((i >= 0) && (j < s.length()))
        {
            i--;
            j++;
            string str = s.substr(i + 1, j - i - 1);

            ans += findBeauty(str, freqMap, freqVec);
        }

        return ans;
    }

    int beautySum(string s)
    {
        int total_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int odd = expandAroundIndex(s, i, i);
            total_count += odd;
            int even = expandAroundIndex(s, i, i + 1);
            total_count += even;
        }
        return total_count / 2;
    }
};



// The above methods is so inefficient and not working
// Method - 3
// Working inefficient method O(n*n*k) only possible
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0 ; i<s.size() ; i++){
            // har new ke liye ek naya map we have to make
            unordered_map<char , int>map;
            for(int j=i ; j<s.size() ; j++){
                // j is the new element string starting from i
                map[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;

                // yeah loop mujhe mini and max dedega
                for(auto ch : map){
                    mini = min(mini , ch.second);
                    maxi = max(maxi , ch.second);
                }
                ans += maxi-mini;
            }
        }
        return ans;
    }
};



