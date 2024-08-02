#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;


void transpose(int arr[][3] , int rows , int cols , int transposeArr[][3]){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            transposeArr[i][j] = arr[j][i];
        }
    }
}


int main(){
    int arr[3][3];
    int rows = 3;
    int cols = 3;
    int transposeArr[3][3];

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cin>>arr[i][j];
        }
    }

    transpose(arr , rows , cols , transposeArr);

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            cout<<transposeArr[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}