#include<iostream>
#include<stack>
using namespace std;


int next(int price , stack<pair<int , int>>&st){
    int span = 1;
    while(!st.empty() && st.top().first <= price){
        span += st.top().second;
        st.pop();
    }
    st.push({price , span});
    return span;
}


int main(){
    stack<pair<int , int>>st;
    int price;
    next(price , st);
return 0;
}