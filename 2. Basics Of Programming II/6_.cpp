// ************************HOME WORK*************************
#include<iostream>
using namespace std;

// 1. Area Of Circle
// float area(int r){
//     return (3.14)*(r*r);
// }

// 2. Find Number is Even or Odd
// void checkNum(int n){
//     if(n%2==0){
//         cout<<"The number "<<n<<" is EVEN";
//     }
//     else{
//         cout<<"The number "<<n<<" is ODD";
//     }
// }

// 3. Find Factorial of a number
// int factorial(int n){
//     int fact=1;
//     // int ans=1;
//     for(int i=1 ; i<=n ; i++){
//         fact = fact*i;
//     }
//     return fact;
// }

// 4. Check Number is Prime or Non Prime
// bool checkNum(int n){
//     if(n<=1){
//         return false;
//     }
//     for(int i=2 ; i<n ; i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// 5. Printing Prime number
// bool checkNum(int n){
//     if(n<=1){
//         return false;
//     }
//     for(int i=2 ; i<n ; i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }
// void printPrimes(int n){
//     for(int i=1 ; i<=n ; i++){
//         if(checkNum(i)){
//             cout<<i<<" ";
//         }
//     }
// }



















// **************************************PROBLEM SOLVING*****************************************
    // 1. Print All Digits in an Integer
    void printDigit(int n){
        int arr[INT_MAX];//Used for storing and we traverse this in reverse order
        int i=0;
        int r;//Used for extraction
        while(n!=0){
            // Extracting the last digit
            r=n%10;

            // Putting digit in array and updating value of i
            arr[i]=r;
            i++;

            // Update N to N/10 to extract next last digit
            n=n/10;
        }

        // i-1 here is the max value of array
        // j>-1 indicates iterating over everyelement above 0 and including 0 it can j>=0 as well
        // Reverse Loop it is
        for(int j=i-1 ; j>-1 ; j--){
            cout<<arr[j]<<" ";
        }
    }

    // 2.Create a number using digits
    int createNumber(int digits[] , int size){
        int number=0;
        int power=1;

        for(int i=size-1 ; i>=0 ; i--){
            number = number + digits[i]*power;
            power=power*10;
        }

        return number;
    }

    // 3.distance in km to miles
    // double kmToMiles(int n){
    //     double num = n * 0.621371;
    //     return num;
    // }

    // 4. print numbers of set bits in c++
    int setBits(int n){
        int count=0;
        while(n!=0){
            count=count+(n&1);
            n>>=1;
        }
        return count;
    }
    
    // 5. Reverse an integer
    // int reverseNum(int digits[] , int size){
    //     int number=0;
    //     int power=1;

    //     int start=0;
    //     int end = size-1;

    //     while(start<=end){
    //         swap(digits[start],digits[end]);
    //         start++;
    //         end--;
    //     }

    //     for(int i=size-1 ; i>=0 ; i--){
    //         number = number + digits[i]*power;
    //         power=power*10;
    //     }

    //     return number;
    // }
    // OR
    int reverseNum(int n){
        int reversed = 0;
        while(n!=0){
            int digit = n%10;
            reversed = reversed*10 + digit;
            n=n/10;
        }
        return reversed;
    }

    // 6. Converting Celcius to Farheniet 
    // float celciusToFarheniet(float c){
    //     float f = (c*1.8)+32;
    //     return f;
    // }








int main(){
    // 1. Area Of Circle
    // int r;
    // cout<<"Enter the value of radius : ";
    // cin>>r;
    // float ans = area(r);
    // cout<<"Area of circle is : "<<ans<<endl;

    // 2. Find Number is Even or Odd
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // checkNum(n);

    // 3. Find Factorial of a number
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // int ans = factorial(n);
    // cout<<"The factorial of "<<n<<" is "<<ans;

    // 4. Check Number is Prime or Non Prime
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // if(checkNum(n)){
    //     cout<<"The number "<<n<<" is Prime";
    // }
    // else{
    //     cout<<"The number "<<n<<" is Non-Prime";
    // }

    // 5. Printing Prime number
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // printPrimes(n);



    





















    // **************************************PROBLEM SOLVING*****************************************
    // 1. Print All Digits in an Integer
    // int n;
    // cout<<"Enter the digit : ";
    // cin>>n;
    // printDigit(n);


    // 2.Create a number using digits
    // int digits[5]={1,2,3,4,5};
    // int size = 5;
    // int number = createNumber(digits , size);
    // cout<<"The number is : "<<number;


    // 3.distance in km to miles
    // int n;
    // cout<<"Enter the distance in km : ";
    // cin>>n;
    // double num = kmToMiles(n);
    // cout<<"The distance in miles is : "<<num;


    // 4. print numbers of set bits in c++
    // int n=12345;
    // int counterBits = setBits(n);
    // cout<<"The number of set bits are : "<<counterBits<<endl;


    // 5. Reverse an integer
    // int digits[6]={9,6,7,8,5,6};
    // int size=6;
    // int ans = reverseNum(digits , size);
    // cout<<"The reversed number of is : "<<ans;
    // OR
    // int n;
    // cout<<"Enter the number : ";
    // cin>>n;
    // int ans = reverseNum(n);
    // cout<<"The reversed number is : "<<ans;


    // 6. Converting Celcius to Farheniet 
    // float c;
    // cout<<"Enter the temp in C : ";
    // cin>>c;
    // float ans = (celciusToFarheniet(c));
    // cout<<"The temp "<<c<<"C into F is :"<<ans;
return 0;
}