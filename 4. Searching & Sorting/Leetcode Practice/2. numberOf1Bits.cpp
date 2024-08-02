#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            // becuase iski wajah se hume sirf last digit hi milegi agar 1 hui toh we can add otherwise adding 0 doesnot matter
            count += n&1;

            // har ek digit jaata rhega bhar baari baari se 
            n = n>>1;
        }
        return count;
    }
};