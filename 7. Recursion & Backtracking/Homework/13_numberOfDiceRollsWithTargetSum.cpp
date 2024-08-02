#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    int numRollsToTargetHelper(int n , int k , int target){
        // base case
        if(target == 0 && n==0){
            return 1;
        }
        if((target < 0) || (target == 0 && n!=0) || (target != 0 && n==0)){
            return 0;
        }
        
        int sum = 0;
        // one case solve
        for(int i=1 ; i<=k ; i++){
            sum += numRollsToTargetHelper(n-1 , k , target-i);
        }
        return sum;
    }

    int numRollsToTarget(int n, int k, int target) {
        return numRollsToTargetHelper(n , k , target);
    }
};

// class Solution {
// public:
//     int numRollsToTargetHelper(int n, int k, int target) {
//         // Base case: If no dice are left
//         if (n == 0) {
//             // If the target is also zero, we've found a valid way to achieve the target
//             return target == 0 ? 1 : 0;
//         }
        
//         // If it's impossible to reach the target with the number of dice left
//         if (target <= 0) {
//             return 0;
//         }

//         int sum = 0;
//         // Try every face of the die
//         for (int i = 1; i <= k; i++) {
//             // Recursively solve for n-1 dice and a new target reduced by the current face value
//             sum += numRollsToTargetHelper(n - 1, k, target - i);
//         }
//         return sum;
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         return numRollsToTargetHelper(n, k, target);
//     }
// };
