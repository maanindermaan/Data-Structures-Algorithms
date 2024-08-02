#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=3){
        return true;
    }
    bool flag = true;
    for(int i=2 ; i<n ; i++){
        if(n%i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<endl;


    if(isPrime(n)){
        cout<<"Yes it a prime number";
    }
    else{
        cout<<"No is not a prime number";
    }
return 0;
}