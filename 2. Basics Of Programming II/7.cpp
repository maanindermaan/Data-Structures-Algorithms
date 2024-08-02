// NUMBER SYSTEM
#include<iostream>
using namespace std;

// int decimalToBinary(int n){
//     // Division Method
//         int binaryNumber=0;
//         int i=0;
//         while(n>0){
//             int bit = n%2;
//             binaryNumber=bit*pow(10,i++)+binaryNumber;
//             n=n/2;
//     }
//     return binaryNumber;
// }

// int decimalToBinary(int n){
//     // Bitwise Method
//         int binaryNumber=0;
//         int i=0;
//         while(n>0){
//             int bit = n & 1;
//             binaryNumber=bit*pow(10,i++)+binaryNumber;
//             n = n>>1;
//     }
//     return binaryNumber;
// } 

int binaryToDecimal(int n){
    // Bitwise Method
        int decimalNumber=0;
        int i=0;
        while(n>0){
            int bit = n % 10;
            decimalNumber =bit*pow(2,i++)+decimalNumber;
            n = n/10;
    }
    return decimalNumber;
} 

int main(){
    int n;
    cin>>n;
    // int binary = decimalToBinary(n);
    // cout<<binary;

    // int binary = binaryToDecimal(n);
    // cout<<binary;
    int x=97;
    int y=sizeof(x++);
    cout<<x;
        
return 0;
}