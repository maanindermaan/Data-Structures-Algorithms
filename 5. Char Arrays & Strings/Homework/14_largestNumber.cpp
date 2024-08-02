#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 1.
static bool mycomparator(string a, string b){
    string t1 = a + b;
    string t2 = b + a;
    return t1>t2;
}

string largestNumber(vector<int>& nums){
    vector<string> snums;
    for(int i = 0; i < nums.size(); i++){
        snums.push_back(to_string(nums[i]));
    }

    sort(snums.begin(), snums.end(), mycomparator);
    
    if(snums[0] == "0"){
        return "0";
    }
    string ans = "";
    for(int i = 0; i <snums.size() ; i++){
        ans += snums[i];
    }
    return ans;
}

int main(){
    vector<int> nums{3, 30, 34, 5, 9};
    cout << largestNumber(nums);
    return 0;
}




// 2. For single digit number code :->
string largestNumber(vector<int>&nums){
    // sort the matrix
    string ans = "";
    sort(nums.begin() , nums.end());
    
    for(int i=nums.size()-1 ; i>=0 ; i--){
        ans.push_back(nums[i] + '0');
    }
    return ans;
}



// 3. Works for single and double but not for maximum digit possible 
bool compare(const int& a, const int& b){
    string num1 = to_string(a);
    string num2 = to_string(b);
    
    return num1[0] < num2[0];
}

string largestNumber(vector<int>&nums){
    // sort the matrix
    string ans = "";
    
    for(int i=0 ; i<nums.size() ; i++){
        cout<<nums[i]<<endl;
    }
    
    sort(nums.begin() , nums.end() , compare);
    
    for(int i=0 ; i<nums.size() ; i++){
        cout<<nums[i]<<endl;
    }
    
    // for(int i=nums.size()-1 ; i>=0 ; i--){
    //     if(nums[i] < 10){
    //         ans.push_back(nums[i] + '0');
    //     }
    //     else{
    //         string number = to_string(nums[i]);
    //         for(auto st : number){
    //             ans.push_back(st);
    //         }
    //     }
    // }
    
    for(int i=nums.size()-1 ; i>=0 ; i--){
        ans += to_string(nums[i]);
    }
    
    return ans;
}



// 4. Final Answer
class Solution {
public:
    static bool compare(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        
        return t1 > t2;
    }

    string largestNumber(vector<int>&nums){
        string ans = "";
        vector<string>snums;

        for(int i=0 ; i<nums.size() ; i++){
            snums.push_back(to_string(nums[i]));
        }
        
        sort(snums.begin() , snums.end() , compare);
        
        if(snums[0] == "0"){
            return "0";
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            ans += snums[i];
        }
        
        return ans;
    }
};


























