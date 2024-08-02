#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void buildAns(stack<string> &s, string &ans)
{ // <-- Pass by reference
    if (s.empty())
    {
        return;
    }
        string temp = s.top();
        s.pop();
        ans += temp;
        buildAns(s,ans);
   }

string simplifyPath(string path)
{
    stack<string> s;
    int i = 0;
    while (i < path.size())
    {
        int start = i;
        int end = i + 1;
        while (end < path.size() && path[end] != '/')
        {
            ++end;
        }
        string minPath = path.substr(start, end - start);
        i = end;
        if (minPath == "/" || minPath == "/.")
        {
            continue; // kuch mat karo
        }
        if (minPath != "/..")
        {
            s.push(minPath);
        }
        else if (!s.empty())
        {
            s.pop();
        }
    }
    string ans;
    if (s.empty())
    {
        ans = "/";
    }
    buildAns(s, ans);
    return ans;
}

int main()
{
    string path = "/a/./b/../../c/";

    string ans = simplifyPath(path);

    cout << ans;
    return 0;
}







// 1.1 Correct above approach only one line error
class Solution {
public:
    void buildAns(stack<string> &s, string &ans)
    { // <-- Pass by reference
        if (s.empty())
        {
            return;
        }
            string temp = s.top();
            s.pop();
            buildAns(s,ans); // we are reversing first now at last we have got the last element and we insert in that order last->first
            ans += temp;
    }

    string simplifyPath(string path)
    {
        stack<string> s;
        int i = 0;
        while (i < path.size())
        {
            int start = i;
            int end = i + 1;
            while (end < path.size() && path[end] != '/')
            {
                ++end;
            }
            string minPath = path.substr(start, end - start);
            i = end;
            if (minPath == "/" || minPath == "/.")
            {
                continue; // kuch mat karo
            }
            if (minPath != "/..")
            {
                s.push(minPath);
            }
            else if (!s.empty())
            {
                s.pop();
            }
        }
        string ans;
        if (s.empty())
        {
            ans = "/";
        }
        buildAns(s, ans);
        return ans;
    }
};
































// 2. Done by myself TLE but working in 20 mins -> BRUTE FORCE very poor
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        while(i<path.size()){
            if(i == path.size()-1 && path[i] == '/'){
                i+=1;
                break;
            }

            if(path.size()-i >= 0 && path.substr(i , 2) == "/."){
                continue;
                i+=2;
            }

            else if(path.size()-i >= 0 && path.substr(i , 2) == "//"){
                st.push(path.substr(i , 1));
                i+=2;
            }

            else if(path.size()-i >= 0 && path.substr(i , 3) == "/.."){
                st.pop();
                i+=3;
            }

            else if(path.size()-i >= 0 && path.substr(i , 1) == "/"){
                st.push(path.substr(i , 1));
                i+=1;
            }
            
            else{
                st.push(path.substr(i , 1));
                i+=1;
            }
        }

        string ans = "";

        // pop out elements and reverse it
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};