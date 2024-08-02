// ALSO KNOWN AS COIN CHANGE PROBLEM
// 1. 5->0
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>&arr , int target){
    // Base Case
    if(target == 0){
        return 0; // 0 banane ke liye 0 elements hi lagenege
    }
    if(target < 0){
        return INT_MAX;
    }

    // ek case solve krdo baaki recursion smabhal lega
    int mini = INT_MAX;
    for(int i=0 ; i<arr.size() ; i++){
        int ans = solve(arr , target - arr[i]);
        if(ans != INT_MAX)
        // vaapis jate hue ek jodenege ki one way to reach target plus hota rhega har baar 
        // becuase it returns mini to ans to +1 karrhe hai har baar ek value increment hokr hi ans mein jarhi hai 
        mini = min(mini , ans+1);
    }

    return mini;
}

int main(){
    vector<int>arr{1,2};
    int target = 5;

    int ans = solve(arr , target);
    cout<<"The answer is : "<<ans;
return 0;
}




// 2. 0->5
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>&arr , int target , int output){
    // Base Case
    if(target == output){
        return 0; // 0 banane ke liye 0 elements hi lagenege
    }
    if(output>target){
        return INT_MAX;
    }

    // ek case solve krdo baaki recursion smabhal lega
    int mini = INT_MAX;
    for(int i=0 ; i<arr.size() ; i++){
        int ans = solve(arr , target , output + arr[i]);
        if(ans != INT_MAX)
        mini = min(mini , ans+1);
    }

    return mini;
}

int main(){
    vector<int>arr{1,2};
    int target = 5;
    int output = 0;

    int ans = solve(arr , target , output);
    cout<<"The answer is : "<<ans;
return 0;
}
