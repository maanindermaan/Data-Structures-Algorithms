#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircle(vector<int> &gas , vector<int> &cost){
    int deficit = 0; // kitna petrol kam padgya
    int balance = 0; // kitna petrol bacha hua hai 
    int startingIndex = 0; // circuit kha se start krrhe ho

    for(int i=0 ; i<gas.size() ; i++){
        // purana petrol lelo jo bacha hua hai naye wala lelo or distance ko mius krdo
        balance = gas[i] - cost[i] + balance;
        if(balance<0){
            deficit = balance + deficit; // + isliye because we consider all possible deficits // Yha galti hogi
            startingIndex = i+1; // jha pe fail hua uske next index se start kro
            balance = 0; // naye start mein petrol zero hoga
        } 
    }
    //  bhar niklne ke bad deficit mein ek negative value padi hai or balance mein koi positive value padi hai
    if(deficit + balance >= 0){
        return startingIndex;
    }
    else{
        // No answer
        return -1;
    }
}


int main(){
    vector<int> gas {4,6,3,4,8};

    vector<int> cost {3,6,7,1,3};

    canCompleteCircle(gas , cost);
return 0;
}