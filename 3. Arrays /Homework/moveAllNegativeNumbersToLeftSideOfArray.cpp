// Move all negative number to left side of an array
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// 1.
// void moveLeftSideOne(vector<int>&v){
//     sort(v.begin() , v.end());
// }


// 2.
void moveLeftSideTwo(vector<int>&v){
    int l = 0;
    int h = v.size()-1;

    while(l<=h){
        if(v[l]<0){
            l++;
        }
        else if(v[h]>0){
            h--;
        }
        else{
            swap(v[l] , v[h]);
            l++;
            h--;
        }
    }
}


int main(){

// vector<int>v{1,-2,9,-10,4,-16,-11};
vector<int>v{1,2,0,0,1,1,0,0,2};

cout<<"Before Moving : "<<endl;
for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}
cout<<endl;

// moveLeftSideOne(v); 

moveLeftSideTwo(v); 

cout<<"After Moving : "<<endl;

for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}

return 0;
}