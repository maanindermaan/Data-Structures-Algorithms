// WAVE PRINT
#include<iostream>
#include<vector>
using namespace std;

void wavePrint(vector<vector<int>>arr){
    int n = arr.size();//->Number of rows
    int m = arr[0].size(); // ->Number of cols
    for(int startCol = 0 ; startCol<m ; startCol++){
        // If Even Number of col top -> bottom
        if(startCol%2 == 0){
            for(int startRow = 0 ; startRow<n ; startRow++){
                cout<<arr[startRow][startCol]<<" ";
            }
        }
        else{
            for(int startRow = n-1 ; startRow>=0 ; startRow--){
                cout<<arr[startRow][startCol]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int>>arr{{1,2,3,4} , {5,6,7,8}  , {9,10,11,12}};
    wavePrint(arr);
return 0;
}