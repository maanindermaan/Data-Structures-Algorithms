// METHOD-1
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// // 2.
// void sort0s1s2s(vector<int>&v){
//     // counting 0s,1s,2s
//     int zeros = 0;
//     int ones = 0;
//     int twos = 0;
    
//     for(int i=0 ; i<v.size() ; i++){
//         if(v[i] == 0){
//             zeros++;
//         }
//         else if(v[i] == 1){
//             ones++;
//         } 
//         else{
//             twos++;
//         }
//     }
    
//     for(int i=0 ; i<zeros ; i++){
//         v[i] = 0;
//     }
//     for(int i=zeros ; i<ones+zeros ; i++){
//         v[i] = 1;
//     }
//     for(int i=ones+zeros ; i<ones+zeros+twos ; i++){
//         v[i] = 2;
//     }
// }


// int main(){

// vector<int>v{1,2,0,0,1,1,0,0,2 , 0 , 0 , 0 , 1 , 2 , 0 , 1 , 0,  1,  0};

// cout<<"Before Moving : "<<endl;
// for(int i=0 ; i<v.size() ; i++){
//     cout<<v[i]<<" ";
// }
// cout<<endl;

// // sort0s1s2s(v); 

// moveLeftSideTwo(v); 

// cout<<"After Moving : "<<endl;

// for(int i=0 ; i<v.size() ; i++){
//     cout<<v[i]<<" ";
// }

// return 0;
// }














// METHOD-2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 2.
void sort0s1s2s(vector<int>&v){
    // counting 0s,1s,2s
    int l = 0;
    int m = 0;
    int h = v.size()-1;
    
    while(m<h){
        if(v[m] == 0){
            swap(v[l] , v[m]);
            m++;
            l++;
        }
        else if(v[m] == 1){
            m++;
        }
        else{
            swap(v[m] , v[h]);
            h--;
        }
    }
}


int main(){

vector<int>v{1,2,0,0,1,1,0,0,2 , 1 , 2};

cout<<"Before Moving : "<<endl;
for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}
cout<<endl;

// moveLeftSideOne(v); 

sort0s1s2s(v); 

cout<<"After Moving : "<<endl;

for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}

return 0;
}