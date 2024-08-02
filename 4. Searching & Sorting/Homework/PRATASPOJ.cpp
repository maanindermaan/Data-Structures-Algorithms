#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossible(vector<int>&cookRanks , int nP , int mid){
    int currPrata = 0; // initially cooked prata
    for(int i=0 ; i<cookRanks.size() ; i++){
        int ranks = cookRanks[i];
        int timeTaken = 0;
        int j = 1;
        while(true){
            if(timeTaken + (j*ranks) <= mid){ //0 + R next iteration R+2R and so soon
                timeTaken = timeTaken + (j*ranks);
                currPrata++;
                j++;
            }
            else{
                break;
            }
        }
        if(currPrata >= nP){
            return true;
        }
    }
    return false;
}


int minTimeToCompleteOrder(vector<int>&cookRanks , int nP){ 
    
    int highestRank = *max_element(cookRanks.begin() , cookRanks.end());
    int start = 0;
    int end = highestRank * (nP * (nP + 1));
    int ans = -1;

    while(start<=end){
        int mid = start + (end - start)/2;
        if(isPossible(cookRanks , nP , mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
 

int main(){
    int nP; // number of pratas
    cout<<"Enter the total pratas you want : ";
    cin>>nP;
    vector<int>cookRanks{1,2,3,4};
    int minTime = minTimeToCompleteOrder(cookRanks , nP);
    cout<<minTime;
return 0;
}