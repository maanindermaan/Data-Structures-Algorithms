#include<iostream>
#include<algorithm>
using namespace std;

int buyLollipops(int n , int prices[]){
    // sort them 
    sort(prices , prices+n);

    // applying algorithm
    int i = 0;
    int j = n-1;
    int cost = 0;

    while(i<j){
        // add cost
        cost += prices[i];

        // increment i and j
        i++;
        j--;
        j--;
    }

    return cost;
}


int main(){
    int n = 6;
    int prices[] = {2,9,8,4,6,7};

    cout<<buyLollipops(n , prices);
return 0;
}