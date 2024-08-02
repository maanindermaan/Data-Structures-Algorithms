// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         // 1.
//         // unordered_map<int, int> counting;

//         // for (int i = 0; i < nums.size(); i++) {
//         //     counting[nums[i]]++;
//         // }

//         // for (auto i : counting) {
//         //     if (i.second == 1) {
//         //         return i.first;
//         //     }
//         // }
//         //     return 0;
//         // }
//         // }

//         // 2.
//         // int ones = 0, twos = 0;

//         // for (int num : nums) {
//         //     ones = (ones ^ num) & ~twos;
//         //     twos = (twos ^ num) & ~ones;
//         // }

//         // return ones;
//         // }

//         // 3.
//         int ones = 0;
//         int twice = 0;
//         int thrice = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             // twice se or isliye kiya hai becuase jab ones zero hoga kyunki humne ones ka code is type se  likha hai ki jab koi bhi same element 2 baar aaye to ones 0 hojaye to do. baar aane ke baad ones 0 hojega but jab element tesri baar ayega or jab twice compare hoyega toh agar OR with prev value nahi karenge toh it will be of great loss. hum twice ko lost krdenge, dry run kro or smaj ayega becuase bech mein koi or element ayega toh vo bhi twice mein update nahi hona chiye
//             twice = twice | (ones & nums[i]);
//             ones = ones ^ nums[i];

//             // jab once or twice same honge matlab element once mein bhi hai or twice mein bhi hai or once or twice alag alag update hue hai to simple 1+2 = 3, vo 3 baar bhi ayega
//             thrice = ones & twice;

//             // updating ones and twice if they are in thrice
//             ones = ones & (~thrice);
//             twice = twice & (~thrice);
//         }
//         return ones;
//     }
// };