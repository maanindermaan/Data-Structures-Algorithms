#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossible(vector<int>&cookRanks , int nP , int mid){
    int currPrata = 0;
    for(int i=0 ; i<cookRanks.size() ; i++){
        int rank = cookRanks[i];
        int j = 1;
        int time = 0;
        while(true){
            if(time + (j*rank) <= mid){
                time += j*rank;
                j++;
                currPrata++;
            }
            else{
                break;
            }
        }
        if(currPrata>=nP){
            return true;
        }
    }
    return false;
}


int minTimeToCompleteOrder(vector<int>&cookRanks , int nP){
    int highestRank = *max_element(cookRanks.begin(), cookRanks.end());
    int start = 0;
    int end = highestRank*(nP*(nP+1));
    int ans = -1;
    
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossible(cookRanks, nP, mid)){
            ans = mid;
//            search in left for min time
            end = mid-1;
        }
        else{
//            search in right
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
    cout<<minTime<<endl;
    return 0;
}
