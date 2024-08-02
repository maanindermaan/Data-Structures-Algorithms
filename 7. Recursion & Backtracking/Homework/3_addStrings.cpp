#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addStrings(const string &s, const string &t, int i, vector<char> &x)
{
    // Base Case
    // considering their lengths are equal
    if (i >= (s + t).size())
    {
        return;
    }

    // Ek case solve krdo
    string result = s + t;
    x.push_back(result[i]);

    // Baaki recursion dekh lega
    addStrings(s, t, i + 1, x);
}

int main()
{
    string s = "abcdef";
    string t = "ghi";
    int i = 0;
    vector<char> x;

    addStrings(s, t, i, x);

    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    return 0;
}


// 2nd method
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addStrings(string &s, string &t, int i)
{
    // base case
    if (i >= t.size()) {
        return;
    }
    s += t[i];
    addStrings(s, t, i + 1);
}

int main()
{
    string s = "abcdef";
    string t = "ghi";
    int i = 0;

    addStrings(s, t, i);

    cout << s << endl;

    return 0;
}
