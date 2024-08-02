// 1.
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int main(){
    
//     vector<int>arr{1,2,3,4,5};
    
//     int size = 5;
//     cout<<"Before Shifting : "<<endl;
//     for(int i=0 ; i<size ; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
    
//     for(int i=0 ; i<size ; i++){
//         if(i+1 <= size-1){
//             swap(arr[i] , arr[i+1]);
//         }
//     }
    
//     cout<<endl;
    
//     cout<<"After Shifting : "<<endl;
//     for(int i=0 ; i<size ; i++){
//         cout<<arr[i]<<" ";
//     }
    
// return 0;
// }



// 2.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    vector<int>arr{1,2,3,4,5};
    int size = 5;
    
    vector<int>rotatedArr(size , 0);
    
    cout<<"Before Shifting : "<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int temp = 0;
    temp = arr[0];
    for(int i=0 ; i<size ; i++){
        rotatedArr[i] = arr[i+1];
    }
    rotatedArr[size-1] = temp;
    
    cout<<endl;
    
    cout<<"After Shifting : "<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<rotatedArr[i]<<" ";
    }
    
return 0;
}