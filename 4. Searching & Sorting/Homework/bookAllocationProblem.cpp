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
        // jis particular value se ye solution ke bhar jarha hai hum use usi value ko remove krdenge ko next ko dedenge or count++ isiliye kiya hai humne

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

bool isPossible2(int arr[] , int N , int M , int sol){
    int pageSum = 0;
    int count = 1;

    for(int i=0 ; i<N ; i++){
        if(arr[i] > sol){
            return false;
        }
        else if(arr[i] + pageSum > sol){
            count++;
            pageSum = arr[i];
            if(count > M){
                return false;
            }
        }
        else{
            pageSum += arr[i];
        }
    }
    return true;
}

int findPagesInBookAllocationProbelem(int arr[] , int N , int M){
    if(M>N){
        return -1;
    }
    int start = 0;
    int end = accumulate(arr , arr+N , 0); // end hamara vo wali position hoti hai jha pe sum of array value aati hai suppose arr[] = {1,2,3,4} end will be at = 1+2+3+4 = 10;
    // We use accumulate() function for that which has starting index  , ending index , initial sum = 0;
    int ans = -1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(isPossible2(arr,N,M,mid)){
            ans = mid;

            // because hume MINIMUM chahiye thats why or chota check kiya left mein jake ans store karake
            end = mid-1;
        }
        // Agar chota possible nahi hai toh bada check karo
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12 , 34 , 67 , 90};
    int M;
    cout<<"Enter the number of students : ";
    cin>>M;
    int N = sizeof(arr) / sizeof(arr[0]);
    int pages = findPagesInBookAllocationProbelem(arr , N , M);
    cout<<"The minimum pages are : "<<pages;
return 0;
}