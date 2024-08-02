#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
public:
    void recursiveHelper(int n , int &ans , vector<int>&perm , vector<bool>&visited , int index){
        // base case
        if(index > n){
            ans++;
            return;
        }

        for(int i=1 ; i<=n ; i++){
            if(!visited[i] && (i % index == 0 || index % i == 0)){
                visited[i] = true;
                perm.push_back(i);

                recursiveHelper(n , ans , perm , visited , index+1);

                perm.pop_back();
                visited[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        int ans = 0;
        vector<int>perm(n+1);
        vector<bool>visited(n+1 , false);

        recursiveHelper(n , ans , perm , visited , 1);

        return ans;
    }
};

// 2.
class Solution {
public:
    void recursiveHelper(int n , int &ans , vector<int>&perm , int currNum){
        // base case
        if(currNum > n){
            ans++;
            return;
        }

        for(int i=1 ; i<=n ; i++){
            if(perm[i] == 0 && (i % currNum == 0 || currNum % i == 0)){
                perm[i] = currNum;

                recursiveHelper(n , ans , perm , currNum+1);

                perm[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        int ans = 0;
        vector<int>perm(n+1);

        recursiveHelper(n , ans , perm , 1);

        return ans;
    }
};