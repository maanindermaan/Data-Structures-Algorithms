// 1. Using Prioirty Queue Method 
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

// Pairs Stored: Each element in the priority queue is a pair<int, int>. When you push a pair into the queue, you are typically pushing something like {cnt, i} where cnt is a count of some items (like 1s in a matrix row) and i is an identifier like a row index.
// Container Used: The vector<pair<int, int>> part does not mean that each pair contains a vector. Instead, it means that the priority queue uses a vector to hold all of its pairs. This vector is not visible or directly accessible when you use the priority queue; it's just the internal storage mechanism.
// Insertion and Storage: When you insert a pair into the priority_queue using pq.push({cnt, i}), the priority_queue uses the ComparePairs comparator to place this new pair in the correct position according to the heap order defined by the comparator. This is all handled internally by the priority queue's algorithms.

struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second; // Compare row indices if counts are equal
        }
        return p1.first < p2.first; // Compare counts
    }
};

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;
    for (int i = 0; i < matrix.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                cnt++;
            }
        }
        if(cnt > 0){
            pq.push({cnt, i});
        }
    }
    if (pq.empty()) {
        return -1; // No rows with any 1s
    }
    auto ans = pq.top();
    return ans.second;
}




// 2. Using Simple Method (not Optimal)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max_count = -1;
    int index = -1;
    for (int i = 0; i < matrix.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                cnt += 1;
            }
        }
        if(cnt > max_count && cnt>0){
            max_count = cnt;
            index = i;
        }
    }
    return index;
}





// 3. Using Binary Search Method
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int max_count = -1;
    int index = -1;
    int cnt = -1;
    int ans = -1;
    for(int i = 0; i < matrix.size(); i++){
        // binary Search Applying in array 
        int start = 0;
        int end = matrix[i].size()-1;
        int mid = 0;

        while(start <= end){
            mid = start + (end-start)/2;

            if(matrix[i][mid] >= 1){
                // store and look for min
                index = mid;
                end = mid-1;
            }
            else{
                // go forward
                start = mid+1;
                index = start;
            }
        }
        cnt = matrix[i].size()-index;
        if(cnt > max_count && cnt>0){
            max_count = cnt;
            ans = i;
        }
    }
    return ans;
}





// 4. Lower Bound Binary Search Method

int lower_bound(vector<int>&arr , int n , int x){
    int start = 0 ;
    int end = n-1;
    int ans = n;

    while(start <= end){
        int mid = start + (end-start)/2;
        // search left
        if(arr[mid] >= x){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int max_count = 0;
    int index = -1;
    for(int i = 0; i < n; i++){
        int cnt_ones = m - lower_bound(matrix[i], m , 1);
        if(cnt_ones > max_count){
            max_count = cnt_ones;
            index = i;
        }
    }
    return index;
}