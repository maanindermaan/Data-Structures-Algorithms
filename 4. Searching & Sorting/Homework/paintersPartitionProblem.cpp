#include<iostream>
#include<numeric>
using namespace std;


bool isPossible(int arr[] , int N , int M , int sol){
    int pageSum=0;
    int count = 1;
    for(int i=0 ; i<N ; i++){
        if(arr[i]>sol){  // current book mein number of pages soln se bade hai. At most 101 pages hi hone chiye bas. ith book mein number of pages 101 se zyada hai. Sum 101 se zyada hai
            return false;
        }
        else if(pageSum + arr[i] > sol){ // jaise hi sum solution se zyada ho jaye count ko bada do. Last ko count mat karo. Last page wali book next count ko allocate krta hu ya next student ko allocate krna. Pehle ko jitni book honi thi vo hu chuki hai 
            count++;
            pageSum = arr[i]; // Jo pichle sum ki values hai unhe chod do or next student ko pehchle sum mat do bas A[i] current position daldo thats it
            if(count>M){
                return false; // count should not be greater than number of students.
            }
        }
        else{
            pageSum = pageSum + arr[i]; // kuch mat karo agar sab sahi hai toh pagesum emin A[i] ki value add krte jao
        }
    }
    return true;
}


int minimumTimeInPainterPartitionProblem(int arr[] , int size , int k){
    int start = 0;
    int end = accumulate(arr , arr+size , 0);
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(arr , size , k , mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {10 , 20 , 30 , 40};
    int k;
    cout<<"Enter the number of workers : ";
    cin>>k;
    int size = sizeof(arr) / sizeof(arr[0]);
    int pages = minimumTimeInPainterPartitionProblem(arr , size , k);
    cout<<"The minimum time taken in units is : "<<pages;
return 0;
}