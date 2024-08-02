#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void recursiveHelper(string s, vector<vector<string> > & ans, vector<string> & part, int index) {
        // base case
        if (index == s.size()) {
            ans.push_back(part);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                part.push_back(s.substr(index, i - index + 1));
                recursiveHelper(s, ans, part, i + 1);
                part.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> part;

        recursiveHelper(s, ans, part, 0);

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string> > result = solution.partition(s);

    cout << "Partitions of the string \"" << s << "\":" << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
