// TARZAN'S ALGORITHM
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &ans, unordered_map<int, list<int>> &adjList)
    {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
                continue;
            if (!vis[nbr])
            {
                // dfs call
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                // low update
                low[src] = min(low[src], low[nbr]);
                // check for bridge

                if (low[nbr] > tin[src])
                {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else
            {
                // node is visited and not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, list<int>> adjList;

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
        int timer = 1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int, bool> vis;
        findBridges(0, -1, timer, tin, low, vis, ans, adjList);

        return ans;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, list<int>> adjList;

        for(int i=0 ; i < connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
        int timer = 1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int, bool> vis;
        findBridges(0, -1, timer, tin, low, vis, ans, adjList);

        return ans;
    }
};

int main()
{
    graph g;
    int n = 4;
    vector<vector<int>> connections{
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}}; 

    vector<vector<int>>ans = g.criticalConnections(n, connections);

    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
