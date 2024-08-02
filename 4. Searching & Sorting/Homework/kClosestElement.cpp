// // Method 1 Two pointer approach
// #include<iostream>
// using namespace std;

// void kClosestElements(vector<int>&arr , int k , int x){
//     int l = 0;
//     int h = arr.size()-1;

//     while((h-l)>=k){
//         if((x-arr[l]) > (arr[h] - x)){
//             l++;
//         }
//         else{
//             h--;
//         }
//     }

//     for(int i=l ; i<=h ; i++){
//         cout<<arr[i]<<" ";
//     }
// }

// int main(){
//     vector<int>arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
//     int k,x;
//     cin>>k>>x;
//     kClosestElements(arr , k , x);
// return 0;
// }







// // Method 2 BINARY SEARCH APPROACH
#include<iostream>
#include<vector>
using namespace std;


int lowerBound(vector<int>&arr , int x){
    int s = 0 , 
    e = arr.size() - 1;
    int ans = e;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(arr[mid]>=x){
            ans = mid;
            e = mid-1;
        }
        if(x>arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<ans;
    return ans;
}

void kClosestElements(vector<int>&arr , int k , int x){
    // Lower Bound
    int h = lowerBound(arr , x);
    int l = h-1;

    while(k--){//if k == 4 loop will run 4 times for k = 4,3,2,1 and will exit when k==0;
        if(l<0){
            h++;
        }
        else if(h>=arr.size()){
            l--;
        }
        else if(x-arr[l] > arr[h]-x){
            h++;
        }
        else{
            l--;
        }
    }

    for(int i=l+1 ; i<=h ; i++){ // donot include l and h
        cout<<arr[i]<<" ";
    }  
}

int main(){
    vector<int>arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k,x;
    cin>>k>>x;
    kClosestElements(arr , k , x);
return 0;
}



// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int l = 0;
//         int h = arr.size()-1;
//         vector<int>ans;

//         while(h-l >= k){
//             if(x-arr[l] > arr[h]-x){
//                 l++;
//             }
//             else{
//                 h--;
//             }
//         }

//         for(int i=l ; i<=h ; i++){
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
// };




// 2. Binary Search Method
// class Solution {
// public:

//     int lowerBound(vector<int>&arr , int x){
//         int s = 0;
//         int e = arr.size()-1;
//         int ans = e;

//         while(s<=e){
//             int mid = s+(e-s)/2;

//             if(arr[mid] >= x){
//                 // store ans and move left
//                 ans = mid;
//                 e = mid-1;
//             }
//             if(arr[mid] < x){
//                 s = mid+1;
//             }
//             else{
//                 e = mid-1;
//             }
//         }
//         cout<<ans<<endl;
//         return ans;
//     }

//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int h = lowerBound(arr , x);
//         int l = h-1;

//         while(k--){
//             if(l < 0){
//                 h++;
//             }
//             else if(h >= arr.size()){
//                 l--;
//             }
//             else if(x-arr[l] > arr[h]-x){
//                 h++;
//             }
//             else{
//                 l--;
//             }
//         }
//         cout<<l<<endl;
//         cout<<h<<endl;
//         return vector<int>(arr.begin() + l + 1 , arr.begin()+h);
//     }
// };