#include<iostream>
#include<vector>
using namespace std;

int ingle(vector<int>& ans){
    int result = 0;

    for(int i=0 ; i<ans.size() ; i++){
        result = result ^ ans[i];
    }
    return result;
}


int main(){
    vector<int> ans = {1,2,1,3,2,5};

    cout<<ingle(ans);
return 0;
}