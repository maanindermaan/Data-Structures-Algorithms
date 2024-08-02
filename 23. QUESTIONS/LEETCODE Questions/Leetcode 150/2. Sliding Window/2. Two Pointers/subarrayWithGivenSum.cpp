#include<iostream>
using namespace std;

vector<int> subarrayWithGivenSum(vector<int>&arr , int target){
    int i = 0;
    int j = 0;
    int ansi = 0;
    int ansj = 0;
    vector<int> ans;
    int sum = 0;

    while(j<arr.size()){
        if(sum < target){
            sum = sum+arr[j];
            j++;
        }

        else if(sum == target){
            ansi = i;
            ansj = j;
            i++;
            j++;
        }

        else{
            sum = sum - arr[i];
            i++;
        }
    }

    for(int index = ansi ; index < ansj ; index++){
        ans.push_back(arr[index]);
    }

    return ans;
}

int main(){
    vector<int>arr{1,5,6,7,15};
    int target = 18;

    vector<int> ans = subarrayWithGivenSum(arr , target);

    for(auto i : ans){
        cout<<i<<" , ";
    }
return 0;
}