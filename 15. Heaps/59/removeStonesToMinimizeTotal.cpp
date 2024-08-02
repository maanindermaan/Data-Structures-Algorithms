#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int minStoneCount(vector<int> &piles , int k){
    priority_queue<int> maxHeap;

    for(int i=0 ; i<piles.size() ; i++){
        maxHeap.push(piles[i]);
    }

    while(!maxHeap.empty() && k--){
        int element = maxHeap.top();
        maxHeap.pop();

        element = element - floor(element/2.0);
        maxHeap.push(element);
    }

    int sum = 0;

    while(!maxHeap.empty()){
        int element = maxHeap.top();
        maxHeap.pop();

        sum = sum + element;
    }
    return sum;
}

int main(){
    vector<int> piles;
    piles.push_back(12);
    piles.push_back(11);
    piles.push_back(8);
    piles.push_back(5);

    int k = 3;

    cout<<minStoneCount(piles , k);
return 0;
}