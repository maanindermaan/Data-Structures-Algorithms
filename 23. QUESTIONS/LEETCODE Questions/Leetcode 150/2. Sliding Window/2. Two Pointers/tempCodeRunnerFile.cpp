#include <iostream>
#include <cctype>
using namespace std;

bool isAlphanumeric(string s) {
    for (char c : s) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "Hello123";
    if (isAlphanumeric(s)) {
        cout << "'" << s << "' is alphanumeric\n";
    } else {
        cout << "'" << s << "' is not alphanumeric\n";
    }
    return 0;
}