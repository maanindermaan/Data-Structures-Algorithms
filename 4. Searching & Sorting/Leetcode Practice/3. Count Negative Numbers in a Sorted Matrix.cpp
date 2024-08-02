#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}


// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int count = 0;
//         for(int i=0 ; i<grid.size() ; i++){
//             for(int j=0 ; j<grid[0].size() ; j++){
//                 if(grid[i][j] < 0){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// binary Search solution
class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int start = 0;
        int end;
        int mid;
        int ans = 0;
        for(auto i : grid){
            end = i.size()-1;
            start = 0;
            ans = -1;
            while (start <= end) {
                mid = start + (end - start) / 2;

                if (i[mid] < 0) {
                    // Increment count and continue searching in the left part
                    ans = mid;
                    end = mid - 1;
                } else {
                    // Search in the right part
                    start = mid + 1;
                }
            }
            if(ans != -1){
                count += i.size()-ans;
            }
        }
        return count;
    }
};
