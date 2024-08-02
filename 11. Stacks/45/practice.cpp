#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
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

        // while(s.top() >= curr){ Ab s.top() to index hai due to 32 to hume yha array ke elemet ko compare karna hoga
        while(s.top() != -1 && input[s.top()] >= curr){ // input is array or vector's name or mai ni chahta ki s.top() -1 hojaye that will cause an error
            s.pop();
        }

        ans[i] = s.top();

        // s.push(curr); hume iss case mein actual element nahi insert karna tha hume element ka index insert karna tha for max Area in Histogram
        s.push(i); 
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    // left -> right = previous Smaller element -> Only for loop changes

    for (int i = input.size()-1; i >= 0 ; i--)
    {
        int curr = input[i];

        // while(s.top() >= curr){ Ab s.top() to index hai due to 32 to hume yha array ke elemet ko compare karna hoga
        while(s.top() != -1 && input[s.top()] >= curr){ // input is array or vector's name or mai ni chahta ki s.top() -1 hojaye that will cause an error
            s.pop();
        }

        ans[i] = s.top();

        // s.push(curr); hume iss case mein actual element nahi insert karna tha hume element ka index insert karna tha for max Area in Histogram
        s.push(i); 
    }
    return ans;
}


int getRectangularAreaHistogram(vector<int>&height){
    // step1 : prev smaller output
    vector<int>prev = prevSmallerElement(height);

    // step2 : next smaller output
    vector<int>next = nextSmallerElement(height);

    int maxArea = INT_MIN;

    for(int i=0 ; i<height.size() ; i++){
        if(next[i] == -1){ // -1 ko 6 se badaldo 
            next[i] = height.size();
        }
        int n = next[i];
        int p = prev[i];

        int width = n-p-1;
        int length = height[i];

        maxArea = max(maxArea , (length*width));
    }
    return maxArea;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout<<"The answer is : "<<getRectangularAreaHistogram(v);
    return 0;
}