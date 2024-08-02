#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<int> applyOperations(vector<int>& arr) {
        for(int i=0 ; i<arr.size() ; i++){
            if(i+1 < arr.size()){
                if(arr[i] == arr[i+1]){
                    arr[i] = arr[i]*2;
                    arr[i+1] = 0;
                }
            }
        }

        // shift zeroes function
        int j = 0;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] != 0){
                swap(arr[i] , arr[j]);
                j++;
            }
        }
        return arr;
    }
};