#include <iostream>
#include <queue>
using namespace std;

bool checkBounds(vector<pair<int, int>> &v, vector<vector<int>> &grid){

    int m = grid.size();
    int n = grid[0].size();

    // 10. Check wehter any of the value of i , j  are out of bound or not
    for(auto pt : v){
        if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= m){
            return false;
        }
    }
    return true;
}

bool getAllVertices(vector<pair<int, int>> &v, vector<vector<int>> &grid, int delta, pair<int, int> c)
{
    // 7. Find all the indexes of A , B , C , D
    pair<int, int> A(c.first - delta, c.second);
    pair<int, int> B(c.first, c.second + delta);
    pair<int, int> C(c.first + delta, c.second);
    pair<int, int> D(c.first, c.second - delta);

    // 8. Push this value to vector strong pair of position(i,j)
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;

    // 9. Check for error bounds
    if(checkBounds(v , grid)){
        return true;
    }
    return false;
}

void getAllSum(vector<vector<int>> &grid, int i, int j, priority_queue<int> &maxHeap)
{
    // 4. Push initial cell
    maxHeap.push(grid[i][j]);

    // 5. Create a delta to not go out of bound
    int delta = 1;

    // 6. Create a pair of vector such that it stores index i , j for particular A , B , C , D
    vector<pair<int, int>> v(4);

    while (getAllVertices(v, grid, delta, {i, j}))
    {

        // 10. Allocate values of A , B , C , D from vector 
        pair<int , int>A = v[0];
        pair<int , int>B = v[1];
        pair<int , int>C = v[2];
        pair<int , int>D = v[3];

        // 11. Find current sum of A , B , C , D first
        int currentSum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        // 12. Find sum of adjoining cells from A-B , B-C , C-D , D-A

        // 13. Sum of all cells between A-B
        for(int i = 1; i<(B.first - A.first) ; i++){
            currentSum += grid[A.first+i][A.second+i];
        }

        // 14. Sum of all cells between B-C
        for(int i = 1; i<(C.first - B.first) ; i++){
            currentSum += grid[B.first+i][B.second-i];
        }

        // 15. Sum of all cells between C-D
        for(int i = 1; i<(C.first - D.first) ; i++){
            currentSum += grid[C.first-i][C.second-i];
        }

        // 16. Sum of all cells between D-A
        for(int i = 1; i<(D.first - A.first) ; i++){
            currentSum += grid[D.first-i][D.second+i];
        }

        // 17. Pus this currentSum into Maxheap
        maxHeap.push(currentSum);

        // 18. For next iteration increase delta
        delta++;
    }
}

bool canPush(vector<int>& ans  , int& top){
    // 22. Checking for same top value into vector
    for(int i=0 ; i< ans.size() ; i++){
        if(ans[i] == top){
            return false;
        }
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    // 1. Create a maxHeap to store maxSum
    priority_queue<int> maxHeap;

    // 2. Find size of matrix
    int m = grid.size(); // row
    int n = grid[0].size();

    // 3. Get all the sum of all of the elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, maxHeap);
        }
    }

    // 19. Now push max into ans vector
    vector<int> ans;

    // 20. I want only first 3 elements
    while(!maxHeap.empty() && ans.size() < 3){
        int top = maxHeap.top();
        maxHeap.pop();

        // 21. If it is safe to push that is safe only when top element is notrepeated.I want unique sums
        if(canPush(ans , top)){
            ans.push_back(top);
        }
    }
    // 23. Return the ans finally
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