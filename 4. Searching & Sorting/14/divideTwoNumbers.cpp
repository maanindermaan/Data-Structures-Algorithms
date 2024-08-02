// Divide Two Numbers Using Binary Search
#include<iostream>
using namespace std;

int solve(int dividend , int divisor){
    int start = 0;
    int end = abs(dividend);// No negative number
    int ans=0;
    while(start<=end){
        int mid = start + (end - start)/2;
        // Perfect Solution
        // if(mid*divisor==abs(dividend)){
        //     return mid;
        // }
        if(abs(mid*divisor)==abs(dividend)){
            ans = mid;
            break;
        }
        else if(abs(mid*divisor) > abs(dividend)){
            // Left Side -> to decrease value of mid
            end = mid-1;
        }
        else if(abs(mid*divisor) < abs(dividend)){
            // Right Side -> to increase value of mid
            // Answer store
            ans = mid;
            start = mid+1;
        }
    }
    // For positive and negative answer
    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
        return ans;
    }
    else{
        return -ans;
    }
}

int main(){
    int dividend = 29;
    int divisor = -7;

    int ans = solve(dividend , divisor);

    cout<<"The quotient is : "<<ans;
return 0;
}