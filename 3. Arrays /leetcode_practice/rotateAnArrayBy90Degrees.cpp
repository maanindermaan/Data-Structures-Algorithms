// // // class Solution {
// // // public:
// // //     void rotate(vector<vector<int>>& v) {
// // //         vector<vector<int>>arr(v.size() , vector<int>(v[0].size() , -1));

// // //         for(int i=0 ; i<v.size() ; i++){
// // //             for(int j=0 ; j<v[0].size() ; j++){
// // //                 if (i == 0) {
// // //                     arr[j][i + v.size() - 1] = v[i][j];
// // //                 } 
// // //                 else if (i == 1){
// // //                     arr[j][i] = v[i][j];
// // //                 } 
// // //                 else if (i == 2){
// // //                     arr[j][v.size() - 1 - i] = v[i][j];
// // //                 }
// // //             }
// // //             cout<<endl;
// // //         }
        
// // //         v = arr;
// // //     }
// // // };



// // class Solution {
// // public:
// //     void rotate(vector<vector<int>>& v) {
// //         vector<vector<int>>arr(v.size() , vector<int>(v[0].size() , -1));
// //         int temp = 0;
// //         for(int i=0 ; i<v.size() ; i++){
// //             for(int j=0 ; j<v[0].size() ; j++){
// //                 arr[j][v[0].size()-1-i] = v[i][j];
// //             }
// //             cout<<endl;
// //         }
        
// //         v = arr;
// //     }
// // };


// class Solution {
// public:
    // void rotate(vector<vector<int>>& v) {
        // 1. Transpose
        // for(int i=0 ; i<v.size() ; i++){
        //     for(int j=i+1 ; j<v[0].size() ; j++){
        //         swap(v[i][j] , v[j][i]);
        //     }
        // }

//         // 2. Column Transpose
//         for(int i=0;i<v.size();i++){
//             reverse(v[i].begin(), v[i].end());
//         }
//     }
// };