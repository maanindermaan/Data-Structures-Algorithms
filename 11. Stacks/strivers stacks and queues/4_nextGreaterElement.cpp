// 1.
// TC -> O(n*n)
// SC -> O(n)

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        stack<int> st;
        st.push(-1);

        for (int i = nums2.size() - 1; i >= 0; i--) {
            cout<<nums2[i]<<endl;
            if (nums2[i] > st.top()) {
                // either -1 or not -1
                if (st.top() == -1) {
                    map[nums2[i]] = st.top();
                } else {
                    // not -1 then pop and check till -1 
                    while (st.top() != -1) {
                        if (nums2[i] < st.top()) {
                            map[nums2[i]] = st.top();
                            break;
                        }
                        st.pop();
                    }
                    if(st.top() == -1){
                        map[nums2[i]] = st.top();
                    }
                }
                st.push(nums2[i]);
            } else {
                // st.top() is bigger
                map[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        
        for(auto i : map){
                cout<<i.first<<" -> "<<i.second<<endl;
            }

        for (int num : nums1) {
            ans.push_back(map[num]);
        }

        return ans;
    }
};



// 2.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& v) {
        unordered_map<int, int> map;
        vector<int> ans;
        stack<int> s;

        for (int i = v.size() - 1; i >= 0; i--) {
            int curr = v[i];
            // Pop elements from the stack until we find a greater element
            while (!s.empty() && s.top() <= curr) {
                s.pop();
            }
            // If stack is empty, there's no greater element
            int next_greater = s.empty() ? -1 : s.top();
            map[curr] = next_greater;
            // Push current element onto the stack
            s.push(curr);
        }

        // Debug print the map
        for (auto i : map) {
            cout << i.first << " -> " << i.second << endl;
        }

        // Prepare the result for nums1 based on the map
        for (int num : nums1) {
            ans.push_back(map[num]);
        }

        return ans;
    }
};




// 3, Striver's
// Same as 2nd one