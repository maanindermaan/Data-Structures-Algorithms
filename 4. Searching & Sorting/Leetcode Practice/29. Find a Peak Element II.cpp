#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1. Brute Force
class Solution {
public:

    bool isPossible(vector<vector<int>>&arr , int row , int col){
        int element = arr[row][col];
        int n = arr.size();
        int m = arr[0].size();
        // saare present the toh 
        if(row-1 >= 0 && element < arr[row-1][col]){
            return false;
        }
        if(row+1 < n && element < arr[row+1][col]){
            return false;
        }
        if(col-1 >= 0 && element < arr[row][col-1]){
            return false;
        }
        if(col+1 < m && element < arr[row][col+1]){
            return false;
        }
        return true;
    }

    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        // brute force
        vector<int>ans;
        for(int i=0 ; i<arr.size() ; i++){
            for(int j=0 ; j<arr[0].size() ; j++){
                if(isPossible(arr , i , j)){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};




// 2. Somewhat better approach 
int findPeakElement(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;

        // if(arr[0] > arr[1]){
        //     return 0;
        // }

        while(s<e){ //<= karenge toh infinite loop mein fasjenge
            if(arr[mid]<arr[mid+1]){
                // We are at line A and move to right
                s = mid+1;
            }
            else{
                // we are at line B move to Line A with peak index in consideration
                // because isme hume search ni karna peak index dena hai bas or agar mid-1 karunga toh elements loss hojaynege
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }

vector<int> findPeakGrid(vector<vector<int>>& arr) {
        // brute force
        vector<int>ans;
        int max_element = -1;
        int ans_row = -1;
        int ans_col = -1;
        for(int row=0 ; row<arr.size() ; row++){
            int col = findPeakElement(arr[row]);
            if(arr[row][col] >= max_element){
                max_element = arr[row][col];
                ans_row = row;
                ans_col = col;
            }
        }
        ans.push_back(ans_row);
        ans.push_back(ans_col);

        return ans;
    }






// 3. Most Optimal approach
class Solution {
public:
    int maxElement(vector<vector<int>>&arr , int m , int n , int mid){
        int maxValue = -1;
        int index = -1;

        for(int i=0 ; i<n ; i++){
            if(arr[i][mid] > maxValue){
                maxValue = arr[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &arr){
        int n = arr.size();
        int m = arr[0].size();
        int start = 0;
        int end = m-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            // which row is having max element 
            int maxRow = maxElement(arr , m , n , mid);

            // we are just checking aage and peeche not uper and neeche becuase max_element in that column must be greater than uper and neeche in that column;
            int left = mid-1 >= 0 ? arr[maxRow][mid-1] : -1;
            int right = mid+1 < m ? arr[maxRow][mid+1] : -1;

            if(arr[maxRow][mid] > left && arr[maxRow][mid] > right){
                return {maxRow , mid};
            }
            else if(arr[maxRow][mid] < left){
                // eliminate right half
                end = mid-1;
            }
            else{
                // eliminate left half
                start = mid+1;
            }
        }
        return {-1 , -1};
    }
};