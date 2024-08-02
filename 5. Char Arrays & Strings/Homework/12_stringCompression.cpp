// Method - 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<char>& s){
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    cout << endl; // Add a newline after printing the vector
}


int compressString(vector<char>&s){
    int index = 0;
    int count = 1;
    char prev = s[0];
    int i = 1;

    for(int i=1 ; i<s.size() ; i++){
        if(s[i] == prev){
            count++;
        }
        else{
            s[index++] = prev; // taki prev dalne ke baad index aage bad ajye
            if(count>1){
                s[index++] = '0' + count;
            }
            prev = s[i];
            count = 1;
        }  
    }
    s[index++] = prev;
    if(count>1){
        s[index++] = '0' + count;
    }
    return index;
}

int main(){
    vector<char> s{'a','a','b','b','c','d','e','e'};
    int ans = compressString(s);
    cout<<ans<<endl;
    printVector(s);
return 0;
}



// Method - 2
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<pair<char, int>> charCount;
        char prevChar = chars[0]; // Initialize prevChar with the first character
        int count = 1; // Initialize count for the first character
        
        // Count the occurrences of each character in chars vector
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == prevChar) {
                count++; // Increment count if the current character matches the previous one
            } else {
                charCount.push_back({prevChar, count}); // Add the pair to the vector
                prevChar = chars[i]; // Update prevChar
                count = 1; // Reset count for the new character
            }
        }
        // Add the last pair
        // for c 3 becuase agar if se update hogya count fir else mein jakar insert thodina hoga at ending of loop
        charCount.push_back({prevChar, count});
        
        chars.clear();

        // Iterate through the vector to reconstruct the chars vector
        for(auto p : charCount){
            chars.push_back(p.first); // Push the character
            if(p.second > 1){
                string countStr = to_string(p.second);
                for (char digit : countStr) {
                    chars.push_back(digit); // Push the count as separate characters
                }
            }
        }
        
        return chars.size();
    }
};