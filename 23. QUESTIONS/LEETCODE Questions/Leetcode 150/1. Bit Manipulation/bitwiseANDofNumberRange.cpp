class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 1. brute force
        // if(left == 0 || right == 0){
        //     return 0;
        // }  
        // int ans = left;

        // int i = left;
        // int j = right; 


        // while(i <= j){
        //     ans = ans & i;
        //     i++; 
        // }
        // return ans;

        // 2. optimal approach
        int shift = 0;
        
        // Find the common leftmost bits
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        // Left shift the common bits back to their original position
        return left << shift;
    }
};