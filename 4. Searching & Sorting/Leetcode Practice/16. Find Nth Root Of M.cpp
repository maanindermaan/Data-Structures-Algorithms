#include<iostream>
using namespace std;
int main(){

return 0;
}

// return 1 if == m
// return 0 if < m
// return 2 if > m
int power(int mid , int n , int m){
    long long ans = 1;
    for(int i=1 ; i<=n ; i++){
        ans = ans*mid;
        if(ans > m){
            return 2;
        }
    }
    if(ans == m){
        return 1;
    }
    return 0;
}


int NthRoot(int n, int m) {
    int start = 1;
    int end = m;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        int target = power(mid , n , m);
        
        if(target == 1){
            return mid;
        }
        
        else if(target == 2){
            // chota karo 
            end = mid-1;
        }
        else{
            // bada karo
            start = mid+1;
        }
    }
    return -1;
}