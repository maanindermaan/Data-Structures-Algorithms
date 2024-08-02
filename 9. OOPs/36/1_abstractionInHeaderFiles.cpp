#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fun(){
    string s = "zmjpwfgabcked";
    sort(s.begin() , s.end());   
    cout<<s<<endl;
}

int main(){
    // vector<int> v {5,4,2,1};
    // sort(v.begin() , v.end()); // we dont know whcih sort is applied
 
    // for(int i=0 ; i<v.size() ; i++){
    //     cout<<v[i];
    // }

    fun();

    return 0;
}
