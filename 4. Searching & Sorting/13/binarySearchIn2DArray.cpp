#include<iostream>
using namespace std;

bool binarySearchInMatrix(int arr[][4] , int rows , int cols ,int target){
    int totalElements = rows*cols;
    int start = 0;
    int end = totalElements-1;

    while(start<=end){
        int mid = start + (end - start)/2;
        int rowIndex = mid/cols;
        int colIndex = mid%cols;

        int element = arr[rowIndex][colIndex];

        if(element == target){
            cout<<"Element found at ("<<rowIndex<<","<<colIndex<<")"<<endl;
            return true;
        }

        else if(target>element){
            // Right Part
            start = mid+1;
        }
        else{
            // Left Part
            end = mid-1;
        }
    }
    return false;
}





bool binarySearchInMatrix(int arr[][4] , int rows , int cols ,int target){
    int totalElements = rows*cols;
    int s = 0;
    int e = totalElements-1;

    while(s <= e){
        int mid = s+(e-s)/2;
        int rowIndex = mid/cols;
        int colIndex = mid%cols;

        int element = arr[rowIndex][colIndex];

        if(element == target){
            return true;
        }
        else if(element > target){
            // left part
            e = mid-1;
        }
        else{
            // right part
            s = mid+1;
        }
    }
    return false;
}





int main(){
    int arr[5][4] = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12} , {13,14,15,16} , {17,18,19,20}};
    int rows = 5;
    int cols = 4;
    int target = 6;

    bool ans =  binarySearchInMatrix(arr , rows , cols , target);

    if(ans){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
return 0;
}