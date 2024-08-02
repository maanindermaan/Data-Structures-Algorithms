#include <iostream>
using namespace std;

// void printDigits(int num){
//     // Base case
//     if(num==0){
//         return;
//     }

//     // baaki recursion sambhal lega
//     printDigits(num/10);

//     // ek case solve kardo;
//     int ans = num%10;
//     cout<<ans<<" ";
// }

void printDigits(int n)
{
    if (n == 0)
    {
        return;
    }

    printDigits(n / 10);

    // modulo 10 gives last digit always
    cout << n % 10<<" ";
}

int main()
{
    int n = 10245;

    printDigits(n);
    return 0;
}