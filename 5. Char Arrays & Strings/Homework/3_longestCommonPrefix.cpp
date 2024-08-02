#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>&arr){
    string ans = " ";
    // For traversing all characters of first string
    for(int i=0 ; i<arr[0].size() ; i++){
        int current_ch = arr[0][i];
        bool match = true;

        // For comparing ch with rest of the strings
        for(int j=1; j<arr.size() ; j++){
            // No match
            if(current_ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }
        else{
            ans.push_back(current_ch);
        }
    }
    return ans;
}

int main(){
    vector<string>arr = {{"flower" , "flow" , "flight"}};
    longestCommonPrefix(arr);
return 0;
}