#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MinStack{
    public: 
    vector<pair<int , int > > st;
    MinStack(){

    }
    void push(int val){
        if(st.empty()){
            //  Agar empty hai to first element bhi val hoga or second bhi val hoga
            // pair<int,int>p = make_pair(val ,val);
            // OR 15-17 
            pair<int,int>p; 
            p.first = val;
            p.second = val;

            // Insert krdiya vector mein
            st.push_back(p);
        }
        else{
            // NON empty
            pair<int,int> p;
            p.first = val;
            p.second = min(val , st.back().second);
            st.push_back(p);
        }
    }

    void pop(){
        st.pop_back();
    }

    int top(){
        return st.back().first;
    }

    int minElement(){
        return st.back().second;
    }
};

int main(){
    MinStack mn;
    mn.push(10);
    mn.push(9);
    mn.push(8);
    mn.push(7);
    mn.push(12);

    cout<<mn.minElement();
return 0;
} 