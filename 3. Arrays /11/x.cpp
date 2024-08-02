#include<iostream>
using namespace std;

// 1.
void rowSum(int arr[][4] , int row , int col){
    int sum;
    for(int i=0 ; i<row ; i++){
        sum = 0;
        for(int j=0 ; j<col ; j++){
            sum += arr[i][j];
        }
        cout<<sum<<endl;
    }
}

// 2.
void colSum(int arr[][4] , int row , int col){
    int sum;
    for(int i=0 ; i<col ; i++){
        sum = 0;
        for(int j=0 ; j<row ; j++){
            sum += arr[j][i];
        }
        cout<<sum<<endl;
    }
}

// 3.
void linearSearch(int arr[][4] , int row , int col , int target){
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(arr[i][j] == target){
                cout<<"YES BABY";
            }   
        }
    }
}

// 4.
void min(int arr[][4] , int row , int col){
    int mini = INT_MAX;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(arr[i][j] < mini){
                mini = arr[i][j];
            }
        }
    }
    cout<<mini<<endl;
}

// 5.
void max(int arr[][4] , int row , int col){
    int maxi = INT_MIN;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(arr[i][j] > maxi){
                maxi = arr[i][j];
            }
        }
    }
    cout<<maxi;
}

// 6.

void transpose(int arr[][4] , int row , int col , int transposed[][4]){
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            transposed[j][i] = arr[i][j];
        }
    }
}

void transpose2(int arr[][4] , int row , int col){
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            swap(arr[i][j] , arr[j][i]);
        }
    }
}

int main(){
    int arr[5][4] = {
        {1,2,3,4},
        {2,3,4,1},
        {5,6,1,3},
        {2,4,6,8},
    };
    int row = 4;
    int col = 4;

    // 1.
    // rowSum(arr , row , col);

    // 2.
    // colSum(arr , row , col);

    // 3.
    // int target = 901;
    // linearSearch(arr, row , col , target);

    // 4.
    // min(arr , row , col);

    // 5.
    // max(arr , row , col);

    // 6.
    // for(int i=0 ; i<row ; i++){
    //     for(int j=0 ; j<col ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int transposed[4][4];

    // transpose(arr , row , col , transposed);

    // for(int i=0 ; i<row ; i++){
    //     for(int j=0 ; j<col ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    
return 0;
}