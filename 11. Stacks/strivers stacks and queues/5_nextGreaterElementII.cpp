#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>st1 , st2;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            st2.push(nums[i]);
        }

        // now our logic 
        for(int i=nums.size()-1 ; i>=0 ; i--){
            int curr = nums[i];

            while(!st1.empty() && curr >= st1.top()){
                st1.pop();
            }

            if(st1.empty()){
                while(!st2.empty() && curr >= st2.top()){
                    st2.pop();
                }
                if(st2.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st2.top();
                }
            }
            else{
                ans[i] = st1.top();
            }
            st1.push(curr);
        }
        return ans;
    }
};



// Striver's method
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge(nums.size());
        stack<int>st;

        int n = nums.size();
        for(int i=2*n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }

            if(i<n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};