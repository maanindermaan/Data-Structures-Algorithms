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

    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];

        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

int getRectangularAreaHistogram(vector<int> &height)
{
    // step1 : prev smaller output
    vector<int> prev = prevSmallerElement(height);

    // step2 : next smaller output
    vector<int> next = nextSmallerElement(height);

    // step3: Finding area
    int maxArea = INT_MIN;

    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];
        if (next[i] == -1)
        { // -1 ko 6 se badaldo
            next[i] = height.size();
        }
        int width = next[i] - prev[i] - 1;

        int area = length * width;

        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int maximumRectangleInMatrix(vector<vector<char>> &matrix)
{
    // converting char matrix to int matrix
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i)
    {
        vector<int> t;
        for (int j = 0; j < m; ++j)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    int area = getRectangularAreaHistogram(v[0]); // sending 1st row

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // lets update current row with previous values;
            if (v[i][j])
            {
                v[i][j] = v[i][j] + v[i - 1][j];
            }
            else{
                // agar 0 hai toh
                v[i][j] = 0;
            }
        }
        area = max(area , getRectangularAreaHistogram(v[i]));
    }
    return area;
}

int main()
{
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

        cout<<"Maximum area is : "<<maximumRectangleInMatrix(matrix);
    return 0;
}
























// 2nd Approach without other areray
class Solution {
public:
    vector<int> prevSmallerElement(vector<int> &input)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(input.size());

        for (int i = 0; i < input.size(); i++)
        {
            int curr = input[i];

            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &input)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(input.size());

        for (int i = input.size() - 1; i >= 0; i--)
        {
            int curr = input[i];

            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    int getRectangularAreaHistogram(vector<int> &height)
    {
        // step1 : prev smaller output
        vector<int> prev = prevSmallerElement(height);

        // step2 : next smaller output
        vector<int> next = nextSmallerElement(height);

        // step3: Finding area
        int maxArea = INT_MIN;

        for (int i = 0; i < height.size(); i++)
        {
            int length = height[i];
            if (next[i] == -1)
            { // -1 ko 6 se badaldo
                next[i] = height.size();
            }
            int width = next[i] - prev[i] - 1;

            int area = length * width;

            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // vector to store heights of histograms
        vector<int> heights(m, 0);
        
        int maxArea = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Update the height of the histogram
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the maximum rectangular area for the current histogram
            maxArea = max(maxArea, getRectangularAreaHistogram(heights));
        }
        
        return maxArea;
    }
};
