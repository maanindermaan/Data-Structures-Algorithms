#include <iostream>
using namespace std;

void findKey(string s, char key, int i)
{
        // Base case
        if (i >= s.size())
        {
                return;
        }

        // 1 case solve krdo
        if (s[i] == key)
        {
                cout << "Yes present at " << i << " index";
        }

        // Baaki recursion sambhal lega
        findKey(s, key, i + 1);
}

int main()
{
        string s = "lovebabbar";
        char key = 'r';
        int i = 0;

        findKey(s, key, i);
        return 0;
}





// #include <iostream>
// #include<vector>
// using namespace std;

// void checkKey(string& str,int i, int& n, char& key, int& count) {
//         //base case
//         if(i >= n) {
//                 //key not found
//                 return ;
//         }
//         //1 case solve krdo
//         if(str[i] == key) {
//                 ///store in vector
//               //ans.push_back(i);
//               count++;
//         }

//         //baaki recursion sambhal lega
//         checkKey(str, i+1, n, key, count);
// }

// void chk(string& str,int i, int& n, char& key, int& count){
//         // base
//         if(i>=n){
//                 return;
//         }
//         if(str[i] == key){
//                 count++;
//         }
//         chk(str , i+1 , n , key , count);
// }

// int main() {
//         string str = "lovebabbar";
//         int n = str.length();

//         char key = 'b';

//         int i = 0;
//         //vector<int> ans;
//         int count = 0;

//         // checkKey(str,i, n, key, count);
//         chk(str,i, n, key, count);
//         cout << count << endl;
//         // cout << "printing ans" << endl;
//         // for(auto val: ans) {
//         //         cout << val << " " ;
//         // }
//         // cout << endl;

//         return 0;
// }