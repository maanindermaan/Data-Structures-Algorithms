#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    // Input
    getline(cin, str);
    // Print
    cout << str << endl;

    // Again 
    getline(cin, str);
    cout << str << endl;

    cout << "length: "<< str.length() << endl;
    cout << "isEmpty: " << str.empty() << endl;

    return 0;
}
