#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> ans;
        
        // Process each query
        for (int i = 0; i < queries; i++) {
            int idx = indices[i];
            int count = 0;
            
            // Count elements greater than arr[idx]
            for (int j = idx + 1; j < n; j++) {
                if (arr[j] > arr[idx]) {
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};