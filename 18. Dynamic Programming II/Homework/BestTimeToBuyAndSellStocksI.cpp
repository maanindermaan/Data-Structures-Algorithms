#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    void maxProfitFinder(vector<int>& prices , int i , int& minPrice , int &maxProfit){
        // base case
        if(i >= prices.size()){
            return;
        }

        if(prices[i] < minPrice){
            minPrice = prices[i];
        }

        if((prices[i] - minPrice)>maxProfit){
            maxProfit = prices[i] - minPrice;
        }

        maxProfitFinder(prices , i+1 , minPrice , maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        maxProfitFinder(prices , 0 , minPrice , maxProfit);

        return maxProfit;
    }
};