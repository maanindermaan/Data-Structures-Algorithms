// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         // 1.
//         int count = 0;
//         while(n!=0){
//             int lastBit = n&1;
//             if(lastBit){
//                 count++;
//             }
//             n = n >> 1;
//         }
//         return count;

//         // 2.
//         // int count = 0;
//         // while(n!=0){
//         //     n = (n & (n-1)) >> 1;
//         //     count ++;
//         // }
//         // return count;
//     }
// };