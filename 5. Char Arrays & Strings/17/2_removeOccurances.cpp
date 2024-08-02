// Remove all occurances of a substring
#include<iostream>
using namespace std;

string removeOccurances(string s , string part){
    // this s.find(part) gives a index
    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos , part.length());
        pos = s.find(part);
    }
    return s;
}

int main(){
    string s , part;
    cin>>s;

    cin>>part;
    cout<<"With Occurances : ";
    cout<<s<<endl;


    string ans = removeOccurances(s , part);

    cout<<"Without Occurances : ";

    cout<<ans<<endl;


return 0;
}



// 2. Not better Time Limit Complexity but done by myself
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;

        string ans;

        while(i < s.length()){
            if(!ans.empty() && ans.back() == part.back()){
                if(ans.find(part) < ans.size()){
                    // milgya ab bas remove krdo
                    int n = part.size();
                    while(n-- && !ans.empty()){
                        ans.pop_back();
                    }
                }
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
            if(i==s.length() && !ans.empty() && ans.find(part) < ans.size()){
                // milgya ab bas remove krdo last baari or
                int n = part.size();
                while(n-- && !ans.empty()){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};