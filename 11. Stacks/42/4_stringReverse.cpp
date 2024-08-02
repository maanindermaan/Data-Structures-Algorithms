// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<string>s;
//     s.push("l");
//     s.push("a");
//     s.push("j");
//     s.push("n");
//     s.push("u");
//     s.push("m");
//     s.push("a");
//     s.push("h");
//     s.push("t");
//     s.push("s");
//     s.push("a");
//     s.push("a");

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
    
// return 0;
// }



#include <iostream>
#include<stack>
using namespace std;

int main() {
  string str = "babbar";

  stack<char> s;
  for(int i=0; i<str.length(); i++) {
          s.push(str[i]);
  }

  while(!s.empty()) {
          cout << s.top() << " ";
          s.pop();
  }
  cout << endl;

  return 0;
}