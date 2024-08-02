// #include<iostream>
// #include<limits.h>
// using namespace std;

// void reorganiseString(string s){
//     int hash[26] = {0}; // considering only small letters 97-122

//     for(int i=0 ; i<s.size() ; i++){
//         hash[s[i] - 'a']++; //hash[s[i]] returns 97 and a also gives 97 and 97-97 = 0 this we way mapped 97 to 0 and also 122-97 = 25 this way we mapped to 25 range (0-25) 26 characters
//     }

//     // Finding the most occurred character
//     char mostOccurredCharacter;
//     int maxOccurrence = INT_MIN;
//     for(int i=0 ; i<26 ; i++){
//         if(hash[i] > maxOccurrence){
//             maxOccurrence = hash[i];
//             mostOccurredCharacter = i + 'a'; // to make it organically into range 97-122
//         }
//     }

//     // Placing most occurred character non-adjacently
//     int index = 0;
//     while(maxOccurrence > 0 && index < s.size()){
//         s[index] = mostOccurredCharacter;
//         index = index + 2;
//         maxOccurrence--;
//     }

//     // If the most occurred character still needs to be placed, no solution exists
//     if(maxOccurrence > 0){
//         cout << "SORRY DARLING";
//         return;
//     }

//     hash[mostOccurredCharacter - 'a'] = 0; // count set to zero, as the most frequent character is already placed

//     // Placing rest of the characters into the array
//     for(int i=0 ; i<26 ; i++){
//         while(hash[i] > 0){
//             if(index >= s.size()){
//                 index = 1;
//             }
//             s[index] = i + 'a';
//             index = index + 2;
//             hash[i]--;
//         }
//     }

//     cout << s;
// }

// int main(){
//     string s = "aaabbbefgg";
//     reorganiseString(s);
//     return 0;
// }





















// USING  HASH  OF  256  CHARS 
#include<iostream>
#include<limits.h>
using namespace std;

void reorganiseString(string s){
    int hash[256] = {0}; // considering big letters 0-255

    for(int i=0 ; i<s.size() ; i++){
        hash[s[i]]++; //hash[s[i]] returns 97 
    }

    // Finding the most occurred character
    char mostOccurredCharacter;
    int maxOccurrence = INT_MIN;
    for(int i=0 ; i<256 ; i++){
        if(hash[i] > maxOccurrence){
            maxOccurrence = hash[i];
            mostOccurredCharacter = i; // to make it organically into range 0-255
        }
    }

    // Placing most occurred character non-adjacently
    int index = 0;
    while(maxOccurrence > 0 && index < s.size()){
        s[index] = mostOccurredCharacter;
        index = index + 2;
        maxOccurrence--;
    }

    // If the most occurred character still needs to be placed, no solution exists
    if(maxOccurrence > 0){
        cout << "SORRY DARLING";
        return;
    }

    hash[mostOccurredCharacter] = 0; // count set to zero, as the most frequent character is already placed

    // Placing rest of the characters into the array
    for(int i=0 ; i<256 ; i++){
        while(hash[i] > 0){
            if(index >= s.size()){
                index = 1;
            }
            s[index] = i;
            index = index + 2;
            hash[i]--;
        }
    }

    cout << s;
}

int main(){
    string s = "aaaaaaaabbbefgg";
    reorganiseString(s);
    return 0;
}
























