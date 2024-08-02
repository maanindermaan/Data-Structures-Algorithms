#include <iostream>
#include <queue>
using namespace std;

bool checkBounds(vector<vector<int>> &grid, vector<pair<int, int>> &v)
{
    int m = grid.size();
    int n = grid[0].size();

    for (auto pt : v)
    {
        if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n)
        {
            return false;
        }
    }
    return true;
}

// Vertices kya hum nikal paye ya nahi
bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, pair<int, int> c, int &delta)
{
    pair<int, int> A(c.first - delta, c.second); // positions (i,j)
    pair<int, int> B(c.first, c.second + delta);
    pair<int, int> C(c.first + delta, c.second);
    pair<int, int> D(c.first, c.second - delta);

    // Push into vector
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;

    if (checkBounds(grid, v))
    {
        return true;
    }
    return false;
}

void getAllSum(vector<vector<int>> &grid, int &i, int &j, priority_queue<int> &maxHeap)
{
    // push rhombus sum of rhombus with area = 0
    maxHeap.push(grid[i][j]);

    // Har point ko consider karna hai before out of bound or usse rhomus banane hai
    int delta = 1;

    // to calculate i , j for A,B,C,D we choose vector pair
    vector<pair<int, int>> v(4);

    // This function will return ABCD
    while (getAllVertices(grid, v, {i, j}, delta))
    {
        // Allocate values to ABC residing in vector v
        pair<int, int> A = v[0];
        pair<int, int> B = v[1];
        pair<int, int> C = v[2];
        pair<int, int> D = v[3];

        // Find Current Sums
        int currentSum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        /*  WRONG METHOD
        // // Sum of all cells between A-B
        // for(int i=A.first+1 ; i<B.first ; i++){
        //     for(int j=A.second+1 ; j<B.second ; j++){
        //         currentSum += grid[i][j];
        //     }
        // }
        
        
        // // Sum of all cells between B-C
        // for(int i=B.first+1 ; i<C.first ; i++){
        //     for(int j=B.second-1 ; j<C.second ; j--){
        //         currentSum += grid[i][j];
        //     }
        // }
        
        
        
        // // Sum of all cells between C-D
        // for(int i=C.first-1 ; i<D.first ; i--){
        //     for(int j=C.second-1 ; j<D.second ; j--){
        //         currentSum += grid[i][j];
        //     }
        // }
        
        
        
        // // Sum of all cells between D-A
        // for(int i=D.first-1 ; i<A.first ; i--){
        //     for(int j=D.second+1 ; j<A.second ; j++){
        //         currentSum += grid[i][j];
        //     }
        // }

        WRONG METHOD
        */


        // Sum of all cells between A-B
        for(int i = 1; i<(B.first - A.first) ; i++){
            currentSum += grid[A.first+i][A.second+i];
        }

        // Sum of all cells between B-C
        for(int i = 1; i<(C.first - B.first) ; i++){
            currentSum += grid[B.first+i][B.second-i];
        }

        // Sum of all cells between C-D
        for(int i = 1; i<(C.first - D.first) ; i++){
            currentSum += grid[C.first-i][C.second-i];
        }

        // Sum of all cells between D-A
        for(int i = 1; i<(D.first - A.first) ; i++){
            currentSum += grid[D.first-i][D.second+i];
        }

        // Pushing Rhombus sum to priority QUEUE
        maxHeap.push(currentSum);
        
        // For next iteration
        delta++;
    }
}


bool canPush(vector<int>&ans , int &top){
    for(int i=0 ; i<ans.size() ; i++){
        if(ans[i] == top){
            return false;
        }
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    vector<int> ans;

    // 1. Make a PQ of maxHeap
    priority_queue<int> maxHeap;
    int m = grid.size();
    int n = grid[0].size();

    // 2.
    // Mujhe har cell ko dekhna hai
    // Har cell ko zero size ka rhombus bhi manna hai
    // Jab har cell ko jab zero size ka rhombus manunga toh mujhe har cell se rhombus bhi banane hai
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, maxHeap);
        }
    }

    while(!maxHeap.empty() && ans.size()<3){
        int top = maxHeap.top();
        maxHeap.pop();

        if(canPush(ans , top)){
            ans.push_back(top);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid{{3, 4, 5, 1, 3},
                             {3, 3, 4, 2, 3},
                             {20, 30, 200, 40, 10},
                             {1, 5, 5, 4, 1},
                             {4, 3, 2, 2, 5}};

    vector<int> ans = getBiggestThree(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}