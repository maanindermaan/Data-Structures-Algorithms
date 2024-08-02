#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

// changes in this code: 
// 1) Element ki jagah index insert kardia at 32.
// 2) ab kyunki index dediya to i have to make sure ki index kisi array ya vector ka ho. Element ko element se compare karana hai
// 3) Or kyunki stack mein -1 tha to i make sure ki -1 na ho tabhi loop ko chalana 25
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

    // right -> left = previous Smaller element -> Only for loop changes

    for (int i = input.size()-1 ; i >= 0 ; i--)
    {
        int curr = input[i];

        while(s.top() != -1 && input[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}


int getRectangularAreaHistogram(vector<int>&height){
    // step1 : prev smaller output
    vector<int>prev = prevSmallerElement(height);

    // step2 : next smaller output
    vector<int>next = nextSmallerElement(height);

    // step3: Finding area
    int maxArea = INT_MIN;

    for(int i=0 ; i<height.size() ; i++){
        int length = height[i];
        if(next[i] == -1){ // -1 ko 6 se badaldo 
            next[i] = height.size();
        }
        int width = next[i]-prev[i]-1;

        int area = length*width;

        maxArea = max(area , maxArea);
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