#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool isPossible(vector<int>&stalls , int cows , int mid){
    //Can we place k cows, with at least mid distance between cows
    int count = 1;
    int pos = stalls[0];

    for(int i=1 ; i<stalls.size() ; i++){
        if(stalls[i] - pos >= mid){
            pos = stalls[i]; // one more cow has been placed
            count++;
        }
        if(count == cows){
            // All cows has been placed
            return true;
        }
    }
    return false;
}


int agressiveCow(vector<int>&stalls , int n , int cows){
    sort(stalls.begin() , stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0]; //maxPos - minPos
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossible(stalls , cows , mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls{1,2,4,8,9};
    int n = stalls.size();
    int cows;
    cout<<"Enter number of Cows : ";
    cin>>cows;
    cout<<endl;
    int ans = agressiveCow(stalls , n , cows);
    cout<<"The minimum distance is : "<<ans;
return 0;
}