// 1. Error coming

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recursiveHelper(vector<pair<int, int>>& sortedMap, vector<int>& quantity, bool& ans, int index) {
        if (index == quantity.size()) {
            ans = true;
            return;
        }

        int number = quantity[index];

        for (auto& it : sortedMap) {
            if (it.second >= number) {
                cout << "The number is: " << it.first << " with occurrence of " << it.second << " and required was " << number << endl;
                it.second -= number;
                cout << "The number is: " << it.first << " with occurrence left of " << it.second << endl;
                recursiveHelper(sortedMap, quantity, ans, index + 1);
                // it.second += number; // backtrack
            }
        }
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        bool ans = false;
        unordered_map<int, int> map;

        for (auto it : nums) {
            map[it]++;
        }

        // Transfer to vector and sort by the second element
        vector<pair<int, int>> sortedMap(map.begin(), map.end());
        sort(sortedMap.begin(), sortedMap.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        for(auto it : map){
            cout<<it.first<<" times "<<it.second<<endl;
        }

        recursiveHelper(sortedMap, quantity, ans, 0);

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<int> quantity = {2, 3, 4};

    bool result = solution.canDistribute(nums, quantity);
    cout << "Can distribute: " << (result ? "Yes" : "No") << endl;

    return 0;
}



// 2. Almost Correct 
class Solution {
public:
    bool recursiveHelper(unordered_map<int, int>& count , vector<int>& quantity , int index){
        if(index == quantity.size()){
            return true;
        }

        for(auto it : count){
            if(it.second >= quantity[index]){
                it.second -= quantity[index];

                if(recursiveHelper(count , quantity , index+1)){
                    return true;
                }

                it.second += quantity[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> count;

        for (auto it : nums) {
            count[it]++;
        }

        return recursiveHelper(count, quantity, 0);
    }
};

// 3. Totally Correct only for loop mistake but TLE
class Solution {
public:
    bool recursiveHelper(vector<int>& count , vector<int>& quantity , int index){
        if(index == quantity.size()){
            return true;
        }

        for(int i=0 ; i<count.size() ; i++){
            if(count[i] >= quantity[index]){
                count[i] -= quantity[index];

                if(recursiveHelper(count , quantity , index+1)){
                    return true;
                }

                count[i] += quantity[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap;

        vector<int>count;


        for (auto it : nums) {
            countMap[it]++;
        }

        for(auto it : countMap){
            count.push_back(it.second);
        }

        return recursiveHelper(count, quantity, 0);
    }
};

// 4. Fully correct 
class Solution {
public:
    bool recursiveHelper(vector<int>& count , vector<int>& quantity , int index){
        if(index == quantity.size()){
            return true;
        }

        for(int i=0 ; i<count.size() ; i++){
            if(count[i] >= quantity[index]){
                count[i] -= quantity[index];

                if(recursiveHelper(count , quantity , index+1)){
                    return true;
                }

                count[i] += quantity[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap;

        vector<int>count;

        sort(quantity.rbegin(), quantity.rend());


        for (auto it : nums) {
            countMap[it]++;
        }

        for(auto it : countMap){
            count.push_back(it.second);
        }

        return recursiveHelper(count, quantity, 0);
    }
};