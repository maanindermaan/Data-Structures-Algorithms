#include<iostream>
using namespace std;

void printSubsequences(string str , string output , int i){    
    //Base Case
    if(i>=str.size()){
        cout<<output<<endl;
        return;
    }

    // exclude 
    printSubsequences(str , output , i+1);

    // include -> Same string pass hoti hai uper wali
    output.push_back(str[i]); // OR YOU CAN SIMPLY DO output = output + str[i]
    printSubsequences(str , output , i+1);
}

int main(){
    string str = "abc";
    string output = " ";
    int i=0;

    printSubsequences(str , output , i);
return 0;
}



// #include<iostream>
// using namespace std;

// void printSubsequences(string str , string output , int i){
    
//     //Base Case
//     if(i>=str.size()){
//         cout<<output<<endl;
//         return;
//     }

//     // include -> Same string pass hoti hai niche so hatana bhi padega jo daala hai
//     output.push_back(str[i]);
//     printSubsequences(str , output , i+1);
//     output.pop_back();

//     // exclude 
//     printSubsequences(str , output , i+1);

// }

// int main(){
//     string str = "abc";
//     string output = " ";
//     int i=0;

//     printSubsequences(str , output , i);
// return 0;
// }





// #include <iostream>
// #include<vector>
// using namespace std;

// void printSubsequences(string str, int n, string output, int i, vector<string>& v) {
//   //base case
//   if(i == n ) {
//     v.push_back(output);
//     return;
//   }

//   //include
//   printSubsequences(str,n, output + str[i], i+1,v);

//   //exclude
//   printSubsequences(str,n, output, i+1,v);


// }

// int main() {
//   string str = "abcd";
//   string output = "";
//   vector<string> v;
//   int i = 0;
//   int n = str.length();
//   printSubsequences(str,n, output, i, v);

//   cout << "Printing all subsequences " << endl;
//   for(auto val: v) {
//     cout << val << " " ; 
//   }

//   cout << endl << "Size of vector is: " << v.size() << endl;

//   return 0;
// }


