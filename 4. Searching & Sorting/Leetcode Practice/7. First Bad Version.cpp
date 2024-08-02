// This question basically means is agar koi kharab hai to usse aage wale saare hi khrab honge 

#include<iostream>
using namespace std;
int main(){

return 0;
}

bool isBadVersion(int n){

}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // to identify first bad version 
        int start = 0;
        int end = n;
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(isBadVersion(mid)){
                // check for small ones now
                ans = mid;
                end = mid-1;
            }
            else{
                // check for right ones
                start = mid+1;
            }
        }
        return ans;
    }
};