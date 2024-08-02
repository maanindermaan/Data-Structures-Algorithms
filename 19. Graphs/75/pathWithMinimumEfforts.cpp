// #include <iostream>
// #include <queue>
// #include <vector>
// #include <limits.h>
// using namespace std;

// int minimumEffortPath(vector<vector<int>> &heights)
// {
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//     // {absDiffernce , {coordinates}}
//     vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
//     // initally push src location
//     pq.push({0, {0, 0}});
//     dist[0][0] = 0;

//     while (!pq.empty())
//     {
//         auto fNode = pq.top();
//         pq.pop();
//         int frontNodeDifference = fNode.first;
//         int x = fNode.second.first;
//         int y = fNode.second.second;

//         // check ans tak toh nahi pahuch agye
//         // check whether x or y is ans or not
//         if (x == heights.size() - 1 && y == heights[0].size() - 1)
//         {
//             return dist[x][y];
//         }

//         // four places to go further
//         int dx[] = {-1, 0, 1, 0};
//         int dy[] = {0, 1, 0, -1};
//         for (int i = 0; i < 4; i++)
//         {
//             int newX = x + dx[i];
//             int newY = y + dy[i];
//             if (newX >= 0 && newY >= 0 && newX < heights.size() && newY < heights[0].size())
//             {
//                 // front node ka difference uper nikala hai or current node ka difference tumhe findout krna hai or dono ka jo bhi
//                 // maximum hoga vo tumhe distance mein dalna hai, agar ye jo dalne lage hai ye distance mein jo dala hua hai usse
//                 // kamm hai toh
//                 int currDifference = abs(heights[x][y] - heights[newX][newY]);
//                 int newMax = max(frontNodeDifference, currDifference);

//                 // agar ye newMax ki value jo distance array mein value padi hai usse kam hai toh isee distance array mein daldo
//                 if (newMax < dist[newX][newY])
//                 {
//                     dist[newX][newY] = newMax;

//                     // distance update krne ke baad pq mein entry push krdo
//                     pq.push({newMax, {newX, newY}});
//                 }
//             }
//         }
//     }
//     return 0;
// }

// int main()
// {
//     vector<vector<int>> heights{
//         {1, 2, 2},
//         {3, 8, 2},
//         {5, 3, 5}};

//     cout << minimumEffortPath(heights);
//     return 0;
// }

// practice
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    // 1. Create a priority queue of minHeap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // 2. Create a distance arrray
    vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));

    // 3. Push intial node to q
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    // 4. traverse while queue is not empty
    while (!pq.empty())
    {
        // 5. Extract frontNode
        auto fnode = pq.top();
        // pop kon krega BKL
        pq.pop();

        int frontNodeDifference = fnode.first;
        int x = fnode.second.first;
        int y = fnode.second.second;

        // 6. Checking whether we have reached the destination or not
        if (x == heights.size() - 1 && y == heights[0].size() - 1)
        {
            return dist[x][y];
        }

        // 7. Finding neighbours while going into the required directions up , down , left , right
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            // 8. Finding new coordinates of neighbours where the node can find the abs difference
            int newX = x + dx[i];
            int newY = y + dy[i];

            // 9. checking whether this new X and newY are under range or not who will check BKL
            if (newX >= 0 && newY >= 0 && newX < heights.size() && newY < heights[0].size())
            {
                // 10. Calculating the new Absolute difference between currnode and neighbour node
                int currNodeDifference = abs(heights[x][y] - heights[newX][newY]);

                // 11. Finding the max between this and previous node difference
                int newMax = max(currNodeDifference, frontNodeDifference);

                // 12. Checking whether this newMax is smaller than we have a value at distance array
                if (newMax < dist[newX][newY])
                {
                    dist[newX][newY] = newMax;

                    // 13. Push into queue after checking all conditions
                    pq.push({newMax, {newX, newY}});
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> heights{
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    cout << minimumEffortPath(heights);
    return 0;
}