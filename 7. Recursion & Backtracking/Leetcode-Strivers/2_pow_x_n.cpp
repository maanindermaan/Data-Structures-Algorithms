#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    double recursiveSol(double x , int n , double& ans){
        // base case
        if(n == 0){
            return ans;
        }

        ans *= x;

        return recursiveSol(x , n-1 , ans);
    }

    double myPow(double x, int n) {
        double ans = 1.00000;

        // handling negative case
        if(n < 0){
            return 1/recursiveSol(x , -n , ans);
        }
        return recursiveSol(x , n , ans);
    }
};