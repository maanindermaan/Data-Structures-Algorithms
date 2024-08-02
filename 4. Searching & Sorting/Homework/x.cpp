#include<iostream>
using namespace std;
int main(){
    int nP = 10;
    int rank = 4 ;
    int count = 1;
    int sol = 0;
    while(count<=nP){
        sol = sol + (count * rank);
        count++;
    }
    cout<<sol;
return 0;
}