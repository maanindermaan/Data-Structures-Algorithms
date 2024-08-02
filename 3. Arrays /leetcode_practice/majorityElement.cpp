// 1. my method worst 
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         vector<pair<int , int>>ans;
//         sort(nums.begin() , nums.end());
//         int count = 0;
//         for(int i=0; i<nums.size() ; i++){
//             if(i+1 < nums.size() && nums[i] == nums[i+1]){
//                 count++;
//             }
//             else if(nums[i] != nums[i+1]){
//                 ans.push_back({nums[i] , count});
//                 count = 0;
//             }
//             else if(i == nums.size()-1){
//                 ans.push_back({nums[i] , count});
//             }
//         }

//         int maxi = 0;

//         for(auto i : ans){
//             if(i.second >= ceil(nums.size()/2)){
                
//                 // if(maxi < i.second){
//                 //     maxi = i.second;
//                 // }
                
//                 maxi = i.first;
//             }
//         }
//         return maxi;
//     }
// };


// 2. Map Solution
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//          unordered_map<int , int>mp; // {key , value}
        
//         for(int i=0 ; i<nums.size() ; i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto i : mp){
//             cout<<i.first<<" "<<i.second<<endl;
//         }
//         int maxi = 0;
//         for(auto i : mp){
//             if(i.second > ceil(nums.size()/2)){
//                 maxi = i.first;
//             }
//         }
//         return maxi;
//     }
// };



// 3. 
// int majorityElement(vector<int>& nums) {

//         int n = nums.size();
//         int key = nums[0];
//         int c=0;

//         for(int i=0;i<n;i++)
//         {
//             if(c == 0){
//                 key = nums[i]; 
//             }  

//             if(nums[i] == key){
//                 c++;
//             }

//             else{
//                 c--;
//             } 
//         }

//         return key;
//     }