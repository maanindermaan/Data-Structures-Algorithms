#include<iostream>
#include<queue>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int>q;
        const int mod = 100000;
        // we are making this to keep track of multiplication values and hence we are storing number of steps to reach that multipcation's answer
        // will also work as visited array in BFS
        vector<int>ans(100000 , -1);
        ans[start] = 0;
        q.push(start);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            if(front == end){
                return ans[end];    
            }
            
            for(auto it : arr){
                int newNode = (front*it)%mod;
                if(ans[newNode] == -1){
                    ans[newNode] = ans[front]+1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};