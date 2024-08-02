
// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;


// void recursiveHelper(string& nums, int target , int currAns ,int index , int& ans){
//     // base case
//     if(index == nums.size() && target == currAns){
//         ans ++;
//         return;
//     }
    
//     for(int i=index ; i<nums.size() ; i++){
//         for(int j=0 ; j<3 ; j++){
//             int num = nums[i] - '0';
//             // +
//             if(j == 0){
//                 currAns += num;
//                 recursiveHelper(nums , target , currAns , i+1 , ans);
//                 currAns -= num;
//             }
            
//             // -
//             if(j==1){
//                 currAns -= num;
//                 recursiveHelper(nums , target  , currAns , i+1 , ans);
//                 currAns += num;
//             }
            
//             // *
//             if(j == 2){
//                 currAns *= num;
//                 recursiveHelper(nums , target  , currAns , i+1 , ans);
//                 currAns /= num;
//             }
//         }
//     }
// }



// int addOperators(string num, int target) {
//     int ans = 0;
//     recursiveHelper(num , target  , 0 , 0 , ans);
    
//     return ans;
// }

// int main() {
//     string num = "123";
//     int target = 6;

//     int result = addOperators(num, target);

//     cout << "Result is "<<result<<endl;
//     cout << endl;

//     return 0;
// }




// correct but how?
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recursiveHelper(string& nums, int target, long long currVal, int index, int& ans, string expr, long long prevNum) {
    // base case
    if (index == nums.size()) {
        if (currVal == target) {
            ans++;
            cout << "Result Number " << ans << " : " << expr << endl;
        }
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (i != index && nums[index] == '0') {
            // Skip leading zero numbers
            break;
        }
        string currStr = nums.substr(index, i - index + 1);
        long long currNum = stoll(currStr);
        cout<<"i : "<<i<<endl;
        cout<<"index : "<<index<<endl;
        cout<<"The number : "<<currNum<<endl;
        if (index == 0) {
            // First number, pick it without any operator
            recursiveHelper(nums, target, currNum, i + 1, ans, currStr, currNum);
        } else {
            // Addition
            recursiveHelper(nums, target, currVal + currNum, i + 1, ans, expr + '+' + currStr, currNum);
            // Subtraction
            recursiveHelper(nums, target, currVal - currNum, i + 1, ans, expr + '-' + currStr, -currNum);
            // Multiplication
            recursiveHelper(nums, target, currVal - prevNum + prevNum * currNum, i + 1, ans, expr + '*' + currStr, prevNum * currNum);
        }
    }
}

int addOperators(string num, int target) {
    int ans = 0;
    recursiveHelper(num, target, 0, 0, ans, "", 0);
    return ans;
}

int main() {
    string num = "123";
    int target = 6;

    int result = addOperators(num, target);

    cout << "Result is " << result << endl;
    cout << endl;

    return 0;
}
