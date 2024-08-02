#include<iostream>
using namespace std;
int main(){

return 0;
}

#include <vector>
#include <string>
using namespace std;

void recursive(int N, vector<string>& ans, string element) {
    // base case
    if (element.size() == N) {
        ans.push_back(element);
        return;
    }

    // solving one case
    if (element.size() == 0 || element.back() == '0') {
        element.push_back('0');
        recursive(N, ans, element);

        // last ko hatake 1 daldiya
        element.back() = '1';
        recursive(N, ans, element);
    } else if (element.back() == '1') {
        element.push_back('0');
        recursive(N, ans, element);
    }
}

vector<string> generateString(int N) {
    vector<string> ans;
    string element;
    recursive(N, ans, element);
    return ans;
}