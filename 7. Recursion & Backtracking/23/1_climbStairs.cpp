#include<iostream>
using namespace std;

int climbStairs(int n){
    // Stopping condtition
    if(n==0 || n==1){
        return 1;
    }
    int ans = (climbStairs(n-1) + climbStairs(n-2));
    return ans;
}

int main(){
    int n; 
    cin>>n;
    cout<<endl;
    int ans = climbStairs(n);
    cout<<ans;
return 0;
}