// // Square root without precison and with precision
// #include<iostream>
// using namespace std;

// int squareRoot(int num){
//     int start = 0;
//     int end = num;
//     int ans=0;
//     while(start<=end){
//         int mid = start + (end - start)/2;
//         if((mid*mid)==num){
//             return mid;
//         }
//         if((mid*mid)>num){
//             // Move to left part
//             end = mid-1;
//         }
//         else{
//             // Move to right part
//             start = mid+1;
//             ans = mid;
//         }
//     }
//     if(ans!=0){
//         return ans;
//     }
//     return -1;
// }

// int main(){
//     int num;
//     cout<<"Enter the number : ";
//     cin>>num;

//     int ans = squareRoot(num);

//     cout<<"The square root of "<<num<<" without precision is : "<<ans<<endl;

//     int precision;
//     cout<<"Enter the value of precision : ";
//     cin>>precision;

//     double step = 0.1;
//     double finalAns = ans;

//     for(int i=0 ; i<precision ; i++){
//         for(double j = finalAns ; j*j<num ; j = j+step){
//             finalAns = j;
//         }
//         step /= 10;
//     }

//     cout<<"The square root of "<<num<<" with precision is : "<<finalAns<<endl;
// return 0;
// }


// Square root without precison and with precision
#include<iostream>
using namespace std;

int squareRoot(int num){
    int start = 0;
    int end = num;
    int ans = 0;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(mid*mid == num){
            return mid;
        }
        else if(mid*mid > num){
            // move to left side then
            end = mid-1;
        }
        else{
            // move to right side but store ans as well
            start = mid+1;
            ans = mid;
        }
    }
    if(ans != 0){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    int ans = squareRoot(num);

    cout<<"The square root of "<<num<<" without precision is : "<<ans<<endl;

    int precision;
    cout<<"Enter the value of precision : ";
    cin>>precision;

    double step = 0.1;
    double finalAns = ans;

    for(int i=0 ; i<precision ; i++){
        for(double j=finalAns ; j*j<num ; j+=step){
            finalAns = j;
        }
        step /= 10;
    }

    cout<<"The square root of "<<num<<" with precision is : "<<finalAns<<endl;
return 0;
}


