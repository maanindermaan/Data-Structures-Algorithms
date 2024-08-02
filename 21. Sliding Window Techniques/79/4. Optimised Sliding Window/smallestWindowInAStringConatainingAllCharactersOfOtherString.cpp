#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

string minWindow(string s, string p)
{
    int len1 = s.length();
    int len2 = p.length();
    int start = 0;

    //  we can print if we have these 2, iss wali character se ye print karade (substr)
    int ansIndex = -1;
    int ansLen = INT_MAX;

    // agar s p se chota hua toh can't search
    if (len1 < len2)
    {
        return "";
    }

    // dono hi string ke characters ka count store krna pdega
    // to make it more optimise use something else than of map
    unordered_map<char, int> strMap; // S
    unordered_map<char, int> patMap; // P
    // to keep track of all characters of P string
    // filling charcaters of P into patmap
    // agar ye saare ke saare characters S wali string ke andar milgye toh i will say its a match
    for (int i = 0; i < p.length(); i++)
    {
        char ch = p[i];
        patMap[ch]++;
    }

    // The count variable is used to keep track of how many characters from p are currently present in the window.
    int count = 0; // iss zero count ko mai exactly p2 ke length tak leke jaunga ki haan itne characters mere
    // paas aachuke hai, uske bad mai comparison karunga
    for (int i = 0; i < s.length(); i++)
    {
        // iss maine map mein insert krdia ki jo bhi window pe mai kaam karrha hu, usme ek character aa chuka
        // hai
        char ch = s[i];

        strMap[ch]++;

        // valid character -> jo character tumhare pattern me bhi ho
        // this condition :-> maanlo tu "toc" pattern ke andar ye 3 character hai, tum kehrhe ho ki count wala
        // jo variable banaya hai isko tum "toc" in teeno ke case mein hi increment karunga. agar "a" hai toh
        // no need to increment

        // kyunki patMap Banchuka hai toh uski freq zyada ho sakti haii
        // ab strMap mein t 2 baar aagya toh mujhe ab count nahi badani hai so that is why <= freq.
        if (strMap[ch] <= patMap[ch]) // freqeuncy
        {
            count++;
        }

        // ek window banchuki hai
        // // window milgyi ab iss window ko choti banao
        if (count == len2)
        {

            // window is readyv

            // minimise the window -> 1. freq decrement, 2. ans update , 3. start ko aage badhana h

            // freq tabhi decrement karunga jab string ke andar extra char present ho
            // the line while (strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0) is a key part of 
            // the algorithm used to minimize the window in the Minimum Window Substring problem. It is used 
            // to determine when to move the start pointer to shrink the window while still maintaining the 
            // count of characters from p in the window.

            // agar frequency of strMap[t] = 2 and patMap[t] = 1. start index is pointing towards t, so s[start] = t.
            // now we have to decrement strMap[t]-- = 1.

            // agar patMap[ch] == 0 i.e. element of s is not present in p, so remove mapping from s and move 
            // start variable forward
            while (strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0)
            {
                // 1. freq decrement
                // hum tab tab aage bada sakte hai 
                // 1) Ya fir extra character pada ho
                // 2) s[start] p mein exist hi nahi karta, jo char p mein exist nahi karta usse compare karane
                //    ka kya fayda
                if (strMap[s[start]] > patMap[s[start]])
                    strMap[s[start]]--;

                // 3. start update
                start++;
            }

            // 2. ans update
            int lengthOfWindow = i - start + 1;
            
            // Finally, it calculates the length of the current window, and if it's shorter than the previously 
            // recorded minimum length (ansLen), it updates ansLen and ansIndex to the current window's values.
            if (lengthOfWindow < ansLen)
            {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }
    // here i act as end 

    // ans not possible
    if (ansIndex == -1)
        return "";

    // ans here
    else
        return s.substr(ansIndex, ansLen);
}

int main()
{
    string s = "timetopractice";
    string p = "toc";

    string ans = minWindow(s, p);

    cout << ans;
    return 0;
}





// // practice
// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// string minWindow(string s, string p)
// {
//     int start = 0;
//     int len1 = s.size();
//     int len2 = p.size();

//     int ansIndex = -1;
//     int ansLength = INT_MAX;

//     if(len2 > len1){
//         return "";
//     }
//     unordered_map<char , int>strMap;
//     unordered_map<char , int>patMap;

//     // insert p's chars
//     for(int i=0 ; i<len2 ; i++){
//         char ch = p[i];
//         patMap[ch]++;
//     }

//     int count = 0; // yeah count mujhe btayega ki kya p milchuki hai dekhna aage length hogi yeah basically

//     for(int i=0 ; i<len1 ; i++){
//         char ch = s[i];
//         strMap[ch]++;


//         if(strMap[ch] <= patMap[ch]){
//             count++;
//         }

//         if(count == len2){
//             // 1. Frequency decrement
//             while(strMap[s[start]] <= patMap[s[start]] || patMap[s[start]] == 0){
//                 if(strMap[s[start]] <= patMap[s[start]]){
//                     strMap[s[start]]--;
//                 }
//                 start++;
//             }
            
//         //  2. Update index and start increment  
//             int length = i - start + 1;

//             if(length < ansLength){
//                 ansIndex = start;
//                 ansLength = length;
//             }
//         }
//     }
//     if(ansLength == INT_MAX){
//         return "";
//     }
//     else{
//         return s.substr(ansIndex , ansLength);
//     }
// }

// int main()
// {
//     string s = "timetopractice";
//     string p = "toc";

//     string ans = minWindow(s, p);

//     cout << ans;
//     return 0;
// }





// practice
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

string minWindow(string s, string p)
{
    int start = 0;
    int len1 = s.size();
    int len2 = p.size();

    int ansLen = INT_MAX;
    int ansIndex = -1;

    unordered_map<char,int>strMap;
    unordered_map<char,int>ptrMap;

    int count = 0;

    if(len2 > len1){
        return "";
    }

    // put elements of p into map
    for(int i=0 ; i<len2 ; i++){
        char ch = p[i];
        ptrMap[ch]++;
    }

    // for string s
    for(int i=0 ; i<len1 ; i++){
        // put elements of s into map
        char ch = s[i];
        strMap[ch]++;

        // count incrementing condition
        if(strMap[ch] <= ptrMap[ch]){
            count++;
        }

        // window milgyi ab iss window ko choti banao
        if(count == len2){
            // decrement kro isko
            // 1. decrementing strMap characters
            // 2. start increment
            // 3. ans update

            while(strMap[s[start]] > ptrMap[s[start]] || ptrMap[s[start]] == 0){
                // 1. 
                if(strMap[s[start]] > ptrMap[s[start]]){
                    strMap[s[start]]--;
                }
                // 2.
                start++;
            }
            // 3.
            int length = i-start+1;

            if(length < ansLen){
                ansLen = length;
                ansIndex = start;
            }
        }
    }
    if(ansLen == INT_MAX){
        return "";
    }
    else{
        return s.substr(ansIndex , ansLen);
    }
}

// practice
string minWindow(string s , string p){
    int len1 = s.length();
    int len2 = p.length();
    int start = 0;

    int ansLen = INT_MAX;
    int ansIndex = 0;

    int count = 0;

    // creating maps
    unordered_map<char , int>strMap;
    unordered_map<char , int>ptrMap;

    // increasing freq of ptrMap
    for(int i=0 ; i<len2 ; i++){
        char ch = p[i];
        ptrMap[ch]++;
    }

    // for strMap
    for(int i=0 ; i<len1 ; i++){
        char ch = s[i];
        strMap[ch]++;

        // increment count accoridngly
        if(strMap[ch] <= ptrMap[ch]){
            count++;
        }

        // now suppose window os size len2 is found
        if(count == len2){
            // 1. decrment freq
            // 2. increment start
            // 3. ans update

            while(strMap[s[start]] > ptrMap[s[start]] || ptrMap[s[start]] == 0){
                // 1.
                if(strMap[s[start]] > ptrMap[s[start]]){
                    strMap[s[start]]--;
                }
                // 2.
                start++;
            }
            // 3.
            int length = i-start+1;
            if(length<ansLen){
                ansLen = length;
                ansIndex = start;
            }
        }
    }
    if(ansLen == INT_MAX){
        return " ";
    }
    return s.substr(ansIndex , ansLen);
}

int main()
{
    string s = "timetopractice";
    string p = "toc";

    string ans = minWindow(s, p);

    cout << ans;
    return 0;
}