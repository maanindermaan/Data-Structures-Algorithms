#include<iostream>
using namespace std;

int maxLen(vector<int>& arr , int n){
    // 1. Create a unordered map
    unordered_map<int , int> map;

    int ans = 0; //maxLen
    int csum = 0;

    // 2. Iterating over the loop
    for(int i=0 ; i<n ; i++){
        int val = arr[i];
        if(val == 0){
            val = -1;
        }
        csum += val;
        // 3. Agar sum zero hai toh
        if(csum == 0){
            // intially sab cancel out hogaye. eg pehle 6 cancel out hogye. 6th element fifth index pe hoga.
            // toh total length index - 0 + 1 se niklegi
            ans = max(ans , i+1);
        }
        // 4. csum map mein daldo
        else if(map.find(csum) == map.end()){
            map[csum] = i;
        }
        else{
            // 5. map has csum already
            ans = max(ans , i-map[csum]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);

    int n = arr.size();

    cout<<maxLen(arr , n);
return 0;
}