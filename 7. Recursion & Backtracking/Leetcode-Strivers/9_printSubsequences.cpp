// method-1
#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}
bool isValid(vector<string>& arr , string& element){
    for(auto& str : arr){
        if(str == element){
            return false;
        }
    }
    return true;
}

void subsequence(vector<string>&arr , string& s , int i , string element){
    // base case
    if(i== s.size()){
        if (isValid(arr, element)) {  // Check for duplicates only at the base case when a subsequence is fully formed
            arr.push_back(element);
        }
        return;
    }

    // one case solve
    // exclude
    subsequence(arr , s , i+1 , element);

    // include
    subsequence(arr, s, i+1, element + s[i]);
}

string moreSubsequence(int n, int m, string a, string b)
{
    vector<string>vector1;
    vector<string>vector2;

    string element1;
    string element2;

    subsequence(vector1, a, 0, element1);
    subsequence(vector2, b, 0, element2);

    if(vector1.size() >= vector2.size()){
        return a;
    }
    return b;
}

// method - 2
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void subsequence(vector<string>& arr, unordered_set<string>& uniqueElements, const string& s, int i, string element) {
    // base case
    if (i == s.size()) {
        // yeah line .second gives false if it is already present 
        // else .second returns true if it is not present
        if (uniqueElements.insert(element).second) {
            arr.push_back(element);
        }
        return;
    }

    // exclude
    subsequence(arr, uniqueElements, s, i + 1, element);

    // include
    subsequence(arr, uniqueElements, s, i + 1, element + s[i]);
}

vector<string> generateUniqueSubsequences(const string& s) {
    vector<string> arr;
    unordered_set<string> uniqueElements;
    subsequence(arr, uniqueElements, s, 0, "");
    return arr;
}

string moreSubsequence(int n, int m, const string& a, const string& b) {
    vector<string> vector1 = generateUniqueSubsequences(a);
    vector<string> vector2 = generateUniqueSubsequences(b);

    return (vector1.size() >= vector2.size()) ? a : b;
}
