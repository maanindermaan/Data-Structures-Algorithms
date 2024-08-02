#include <iostream>
using namespace std;
int main()
{

    return 0;
}

class Solution
{
public:
    // checking whether it is a valid substring or not, it is valid if all elements of words are present in it
    bool checkSubstring(unordered_map<string, int> wordCount, string str, int wordLen)
    {
        // we jumping wordLen each time becuse we are checking for substring w i.e. of wordLen size
        for (int j = 0; j < str.size(); j = j + wordLen)
        {
            // making further a substring of size wordLen to check whether it is present in string str
            string w = str.substr(j, wordLen);

            // checking if this w is present in our wordCount map or not or present in words array or not
            // found
            if (wordCount.find(w) != wordCount.end())
            {
                // check if the freq. is 0 or not
                if (wordCount[w] == 0)
                {
                    return false;
                }
                // if found and not 0 decrese freq
                else
                {
                    wordCount[w]--;
                }
            }
            // not found
            else
            {
                return false;
            }
        }
        // if it would have been false it would have returned, if not returned then true
        return true;
    }
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int sLen = s.size();
        int wordLen = words[0].size();
        int wordWindow = wordLen * words.size();
        vector<int> ans;

        // create a map to store all the occurances of wordWindow
        unordered_map<string, int> wordCount;

        // fill this map
        for (auto i : words)
        {
            wordCount[i]++;
        }

        // now checking for the words vector into s
        int index = 0;
        // ending condition
        while (index + wordWindow <= sLen)
        {
            // now we are sending a substring from s of the size we need i.e.e wordWindow size and now we will check whether this substring is containing all elements of words or not , if containing we will store the ans i.e. index from string s i.e. i so that's why we are starting from posn 0
            if (checkSubstring(wordCount, s.substr(index, wordWindow), wordLen))
            {
                ans.push_back(index);
            }
            // increment for next index
            index++;
        }
        return ans;
    }
};