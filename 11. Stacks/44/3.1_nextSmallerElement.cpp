#include <iostream>
#include<vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans(v.size());
    stack<int> s;
    s.push(-1);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        // Mai ab 3 pe khada hu i=3; and v[i] = 3
        int curr = v[i];
        // Jab tak chota na mile pop krte raho
        // aapka ans stack mein
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans.push_back(s.top());
        // chota element mil chuka hai ans store
        ans[i] = s.top();

        // push krdo current element ko 
        s.push(curr);
    }

    cout<<"Printing"<<endl;
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}