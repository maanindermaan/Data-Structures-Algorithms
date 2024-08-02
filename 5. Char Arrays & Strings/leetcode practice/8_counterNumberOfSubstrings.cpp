// Method - 1 -> TLE
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool countOcc(string s, int k)
{
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }
    if (map.size() > k)
    {
        return false;
    }
    return true;
}

bool countOcc(string s, int k)
{
    unordered_map<char, int> map;
    int distinctCount = 0;

    for (char c : s)
    {
        if (map[c] == 0)
        {
            distinctCount++;
        }
        map[c]++;
    }

    return distinctCount == k;
}

int main()
{
    string s = "ecbaddce";
    int k = 3;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (j - i + 1 >= k && countOcc(s.substr(i, j - i + 1), k))
            {
                cout << s.substr(i, j - i + 1) << endl;
            }
        }
    }
    return 0;
}

// Method 2 -> ERROR
class Solution
{
public:
    long long int expandAroundIndex(string &s, int i, int j, int k)
    {
        long long int cnt = 0;
        long long int count_distinct = 0;
        unordered_map<char, int> map;

        while (i >= 0 && j < s.size())
        {
            if (map[s[i]] == 0)
            {
                count_distinct++;
            }
            if (map[s[j]] == 0)
            {
                count_distinct++;
            }
            map[s[i]]++;
            map[s[j]]++;
            i--;
            j++;

            if (count_distinct == k)
            {
                cnt++;
            }

            if (map.size() == 1)
            {
                for (auto ch : map)
                {
                    if (ch.second >= k)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    long long int substrCount(string s, int k)
    {
        long long int total_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // for odd
            long long int oddKaAns = expandAroundIndex(s, i, i, k);
            total_count += oddKaAns;

            // for even
            long long int evenKaAns = expandAroundIndex(s, i, i + 1, k);
            total_count += evenKaAns;
        }
        return total_count;
    }
};


// Method - 3 Most Optimised O(n) 
class Solution
{
  public:
    long long substringWithAtLeastKDistinct(string& s , int n , int k){
        int l , r , c[26] , count_distinct=0;
        long long ans_count = 0;
        
        for(l=0 ; l<26 ; l++){
            c[l] = 0;
        }
        l=r=0;
        
        for(int l=0 ; l<n ; l++){
            while(r<n && count_distinct<k){
                // incrementing count of rth character
                c[s[r]-97]++;
                if(c[s[r]-97] == 1){
                    count_distinct++;
                }
                r++;
            }
            
            if(count_distinct >= k){
                ans_count = ans_count + n-r + 1;
            }
            
            //  l is starting index where window starts 
            c[s[l]-97]--;
            if(c[s[l] - 97] == 0){
                count_distinct--;
            }
        }
        return ans_count;
    }
    
    long long int substrCount (string s, int k) {
    	long long ans = 0;
    	
    	ans = substringWithAtLeastKDistinct(s , s.size() , k) - substringWithAtLeastKDistinct(s , s.size() , k+1);
    	
    	return ans;
    }
};

