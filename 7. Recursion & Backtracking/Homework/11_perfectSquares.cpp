#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    int recuriveCalls(int num){
        if(num == 0){
            return 0;
        }
        if(num < 0){
            return INT_MAX;
        }
        int finalAns = INT_MAX;

        for(int i=1 ; i<= sqrt(num) ; i++){
            int ans = recuriveCalls(num - (i*i));
            // ans mein +1 karna hi padega otherwise , it means ki itna plus hogya depth mein 
            finalAns = min(finalAns , ans+1);
        }

        return finalAns;
    }

    int numSquares(int n) {
        return recuriveCalls(n);
    }
};


// Method-2 -> More or less they're same
class Solution {
public:
    int numSquareHelper(int n){
        //base 
        if(n ==0) return 1;
        if(n < 0) return 0;
        
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberofPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if (numberofPerfectSquares < ans) {
                ans = numberofPerfectSquares;
            }
            ++i;
        }
        return ans;
    }

    int numSquares(int n) {
        return numSquareHelper(n)-1;
    }
};

// Method - 3
class Solution {
public:
    int numSquareHelper(int n){
        //base 
        if(n ==0) return 0;
        if(n < 0) return 0;
        
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberofPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if (numberofPerfectSquares < ans) {
                ans = numberofPerfectSquares;
            }
            ++i;
        }
        return ans;
    }

    int numSquares(int n) {
        return numSquareHelper(n);
    }
};