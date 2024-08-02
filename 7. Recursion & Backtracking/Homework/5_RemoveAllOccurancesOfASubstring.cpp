#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    void removeRecursively(string& s , string& part){
        if(s.find(part) == string::npos){
            // nahi mila
            return;
        }
        // we directly erased here 
        // but we can also do one think ki iss index se pehle wale element + iss index se baad wale elemnt ko leke jod du
        // eg s=dabcccbad either i can erase directly or i can do s_left = dab and s_right = bad and s=s_left+s_right = dabbad

        // if(s.find(part) != string::npos){
        //     s.erase(s.find(part) , part.size());
        // }

        if(s.find(part) != string::npos){
            string s_left = s.substr(0 , s.find(part));
            string s_right = s.substr(s.find(part) + part.size() , s.size());
            s = s_left + s_right;
        }
        removeRecursively(s , part);
    }

    string removeOccurrences(string s, string part) {
        removeRecursively(s , part);
        return s;
    }
};