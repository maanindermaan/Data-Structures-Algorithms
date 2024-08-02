#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // creation 
    unordered_map<char , int> mapping; // {key , value}

    string s = "thiruvananthapuram";

    // Making key value in the map
    for(int i=0 ; i<s.size() ; i++){
        char ch = s[i];
        mapping[ch]++;
    }

    // Prining the map 
    for(auto i : mapping){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
return 0;
}


// #include<iostream>
// #include<unordered_map>
// using namespace std;
// int main(){
//     // creation 
//     // unordered_map<char , int> mapping; // {key , value}
//     int freq[25] = {0};

//     string s = "thiruvananthapuram";

//     // Making key value in the map
//     for(int i=0 ; i<s.size() ; i++){
//         char ch = s[i];
//         freq[ch - 'a']++;
//     }


//     // Prining the map 
//     for(int i=0 ; i<26 ; i++){
//         cout<<freq[i]<<endl;
//     }
// return 0;
// }