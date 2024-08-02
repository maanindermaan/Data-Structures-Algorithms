#include<iostream>
using namespace std;

void printAllSubstrings(string s) {
    int n = s.size();

    // Generate all substrings starting from each character
    for (int i = 0; i < n; i++) {
        // Generate substrings of length 1 to n-i
        for (int len = 1; len <= n - i; len++) {
            string substring = s.substr(i, len);
            cout << substring << endl;
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "All substrings of \"" << s << "\": " << endl;
    printAllSubstrings(s);

    return 0;
}
