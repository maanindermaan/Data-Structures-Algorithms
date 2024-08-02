#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start = 0;
        long long int end = sqrt(c);

        while(start <= end){
            long long int sum = (start*start) + (end*end);
            if(sum == c){
                return true;
            }
            else if(sum < c){
                start++;
            }
            else{
                end--;
            }
        }
        return false;
    }
};