#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int mincostTicketsHelper(vector<int>&days , vector<int>&costs , int i){
        // Base Case
        if(i >= days.size()){
            return 0;
        }

        // One case solve
        int cost0 = costs[0] + mincostTicketsHelper(days , costs , i+1);

        int j = i;
        while(j<days.size() && days[j] < days[i] + 7){
            j++;
        }
        int cost1 = costs[1] + mincostTicketsHelper(days , costs , j);

        int k = i;
        while(k<days.size() && days[k] < days[i] + 30){
            k++;
        }
        int cost2 = costs[2] + mincostTicketsHelper(days , costs , k);

        return min(cost0 , min(cost1 , cost2));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTicketsHelper(days , costs , 0);
    }
};