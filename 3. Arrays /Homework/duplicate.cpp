// Duplicate Element 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// 1. Sort Approach
// void duplicate(vector<int>&v){
//     sort(v.begin() , v.end());
//     for(int i=0 ; i<v.size() ; i++){
//         if(v[i]==v[i+1]){
//             cout<<"Duplcate element found : "<<i;
//         }
//     }
// }


// 2. visited solution approach
// void duplicate(vector<int>&v){
//     int ans = -1;
//     for(int i=0 ; i<v.size() ; i++){
//         int index = abs(v[i]);

//         // Already Visited
//         if(v[index]<0){
//             ans = index;
//             cout<<"Duplicate element found : "<<ans;
//             break;
//         }

//         // Visited mark
//         v[index] *= -1;
//     }
// }

// 3. Positioning Method
int duplicate(vector<int>&v){
    while(v[0]!=v[v[0]]){
        swap(v[0] , v[v[0]]);
    }
    return v[0];
}



int main(){

vector<int>v{1,3,4,2,2};

for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}
cout<<endl;
// duplicate(v);
// int ans = duplicate(v); 
// cout<<ans;

return 0;
}