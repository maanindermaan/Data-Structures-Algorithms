// APPROACH 1 NOT WORKING FIND OUT WHYYYYYYY
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string getLongestSubstring(string &s, int k)
{
    string ans = "";
    priority_queue<pair<int, string>> maxHeap;
    queue<char> q;
    unordered_map<char, bool> mapping;
    string temp = "";

    // for first k sized window
    for (int i = 0; i < k; i++)
    {
        char ch = s[i];
        if (mapping[ch] == false)
        {
            q.push(ch);
            mapping[ch] = true;
        }
    }

    // extract from queue
    while (!q.empty())
    {
        char top = q.front();
        q.pop();

        temp.push_back(top);
    }

    // push this temp into maxheap
    int tempLength = temp.length();
    maxHeap.push({tempLength, temp});


    // printing till here
    while (!maxHeap.empty())
    {
        pair<int, string> element = maxHeap.top();
        cout << "Length: " << element.first << ", Substring: " << element.second << endl;
        maxHeap.pop();
    }

    // for remaining windows
    for (int i = k; i < s.size(); i++)
    {
        string remaining = "";
        // out of bound index removing and mapping of that element is made false now
        if (!q.empty())
        {
            char ch = q.front();
            q.pop();
            mapping[ch] = false;
        }

        // push new char to q and also just remove mapping of those which are popped now
        char newChar = s[i];
        if (mapping[newChar] == false)
        {
            q.push(newChar);
            mapping[newChar] = true;
        }

        // extract from queue
        queue<char> tempQueue = q; // Create a temporary queue to avoid emptying q
        while (!tempQueue.empty())
        {
            char top = tempQueue.front();
            tempQueue.pop();

            remaining.push_back(top);
        }

        // push this temp into maxheap
        int remainingLength = remaining.length();
        maxHeap.push({remainingLength, remaining});
    }
    // extract from maxheap now
    if (!maxHeap.empty())
    {
        pair<int, string> local = maxHeap.top();
        ans = local.second;
    }
    return ans;
}

int main()
{
    string s = "abccddddefffghijk";

    int k = 5;

    cout << getLongestSubstring(s, k);
    return 0;
}























// APPROACH 2
#include <iostream>
#include <unordered_set>
using namespace std;

string getLongestSubstring(string &s, int windowSize)
{
    if (windowSize <= 0 || windowSize > s.size()) {
        return ""; // Invalid window size
    }

    string ans = "";
    int n = s.size();

    for (int start = 0; start <= n - windowSize; start++)
    {
        unordered_set<char> seen;

        int end;
        for (end = start; end < start + windowSize; end++)
        {
            if (seen.find(s[end]) != seen.end()) {
                break; // Repeating character found, exit the loop
            }
            seen.insert(s[end]);
        }

        if (end - start > ans.size()) {
            ans = s.substr(start, end - start);
        }
    }

    return ans;
}

int main()
{
    string s = "abccddddefffghijk";
    int windowSize = 5;
    cout << getLongestSubstring(s, windowSize);
    return 0;
}

























// APPROACH 3
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestUniqueSubstringInWindow(const string &s, int window_size) {
    if (window_size <= 0 || window_size > s.length()) {
        return 0;
    }
    
    int window_start = 0;
    int max_length = 0;
    unordered_map<char, int> char_index_map;  // Map to store the last seen index of each character
    
    for (int window_end = 0; window_end < s.length(); ++window_end) {
        char current_char = s[window_end];
        
        // If the current character has been seen within the current window,
        // update the window's start index to the next index after the last occurrence of the character.
        if (char_index_map.find(current_char) != char_index_map.end() && char_index_map[current_char] >= window_start) {
            window_start = char_index_map[current_char] + 1;
        }
        
        // Update the last seen index of the current character.
        char_index_map[current_char] = window_end;
        
        // Calculate the length of the current window and update max_length if needed.
        int current_length = window_end - window_start + 1;
        max_length = max(max_length, current_length);
        
        // Shrink the window if it's larger than the specified window size.
        if (current_length > window_size) {
            ++window_start;
        }
    }
    
    return max_length;
}

int main() {
    string input = "abcabcbb";
    int window_size = 3;
    
    int result = longestUniqueSubstringInWindow(input, window_size);
    cout << "Length of longest substring with unique characters within window: " << result << endl;
    
    return 0;
}
