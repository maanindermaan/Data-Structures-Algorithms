#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// bool isPossible(vector<long long int>&trees , long long int m , long long int mid){
//     long long int woodCollected = 0;
//     for(int i=0 ; i<trees.size() ; i++){
//         if(trees[i] > mid){
//             woodCollected = woodCollected + trees[i] - mid;
//         }
//     }
//     if(woodCollected >= m){
//         return true;
//     }
//     return false;
// }


// int maxSawBladeHeight(vector<long long int>&trees , int m){
//     sort(trees.begin() , trees.end());
//     long long start = 0;
//     long long end = *max_element(trees.begin() , trees.end());
//     long long ans = -1;

//     while(start<=end){
//         long long int mid = start + (end - start)/2;
//         if(isPossible(trees , m , mid)){
//             ans = mid;
//             start = mid+1;
//         }
//         else{
//             end = mid-1;
//         }
//     }
//     return ans;
// }





bool isPossible(vector<long long>&trees , long long m , int mid){
    long long int woodLength = 0;

    for(int i=0 ; i<trees.size() ; i++){
        if(trees[i] > mid){
            woodLength = woodLength + trees[i]-mid;
        }
    }

    if(woodLength < m){
        return false;
    }
    return true;
}


int maxSawBladeHeight(vector<long long>&trees , long long m){
    int start = 0;
    int end = *max_element(trees.begin() , trees.end());
    int ans = -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(trees , m , mid)){
            ans = mid;
            // right
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}







int main(){
    long long int m;
    cout<<"Enter the total woods you want : ";
    cin>>m;
    vector<long long int>trees {20,15,10,17};
    int height = maxSawBladeHeight(trees , m);
return 0;
}