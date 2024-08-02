#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    // left -> right = previous Smaller element -> Only for loop changes

    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans = prevSmallerElement(v);

    cout<<"Printing"<<endl;
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}