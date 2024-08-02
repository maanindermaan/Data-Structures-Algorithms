#include<iostream>
#include<stack>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxAns = 0;
        int count = 0;

        for(auto ch : s){
            if(ch == '('){
                st.push(ch);
                count++;
            }
            else if(ch == ')'){
                if(count > maxAns){
                    maxAns = count;
                }
                st.pop();
                count--;
            }
        }

        return maxAns;
    }
};



// Method -2 Without stack
class Solution {
public:
    int maxDepth(string s) {
        int maxAns = 0;
        int count = 0;

        for(auto ch : s){
            if(ch == '('){
                count++;
            }
            else if(ch == ')'){
                if(count > maxAns){
                    maxAns = count;
                }
                count--;
            }
        }
        return maxAns;
    }
};