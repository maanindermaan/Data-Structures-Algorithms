// // Factorial of a large number
#include<iostream>
#include<vector>
using namespace std;

void findFactorial(vector<int>&factorial , int N){
    factorial.push_back(1);
    int carry = 0;
    for(int i=2 ; i<=N ; i++){
        for(int j=0 ; j<factorial.size() ; j++){
            int ans = factorial[j]*i+carry;
            factorial[j] = ans%10;
            carry = ans/10;
        }
        while(carry>0){
            factorial.push_back(carry%10);
            carry = carry/10;
        }
    }
}

int main(){
    int N;
    cout<<"Enter the value of N : ";
    cin>>N;
    vector<int>factorial;

    findFactorial(factorial , N);

    cout<<"The factorial of the number is : ";
    for(int i=factorial.size()-1 ; i>=0 ; i--){
        cout<<factorial[i];
    }
return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;

// void findFactorial(vector<int>& factorial, int N) {
//     factorial.push_back(1);
//     int carry = 0;
//     for (int i = 2; i <= N; i++) {
//         for (int j = 0; j < factorial.size(); j++) {
//             int ans = factorial[j] * i + carry;
//             factorial[j] = ans % 10;
//             carry = ans / 10;
//         }
//         while (carry > 0) {
//             factorial.push_back(carry % 10);
//             carry /= 10;
//         }
//     }
// }

// int main() {
//     int N;
//     cout << "Enter the value of N: ";
//     cin >> N;
//     vector<int> factorial;

//     findFactorial(factorial, N);

//     cout << "The factorial of the number is: ";
//     for (int i = factorial.size() - 1; i >= 0; i--) {
//         cout << factorial[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
