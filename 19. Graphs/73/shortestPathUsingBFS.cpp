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
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction) // if wt = 1, no need to include this
    {
        // direction = 1 -> undirected graph
        // direction => 0 -> directed graph;
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // intial step for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])   // list<pair<int, int>> this is nbr and nbr.first is node and 
                //  nbr.second is weight
                {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        //store path in ans, after traversing in the parent array
        vector<int> ans;
        int node = dest;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        // to skip this 
        reverse(ans.begin(), ans.end());

        cout << "printing ANS: " << endl;
        for (auto i : ans)
        {
            cout << i << ", ";
        }
        cout << endl;
    }


    void shortestPath(int src , int dest){
        unordered_map<int , bool> visited;
        unordered_map<int , int> parent;

        queue<int>q;
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while(!q.empty()){
            int fnode = q.front();
            q.pop();

            for(auto nbr : adjList[fnode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fnode;
                }
            }
        }

        int node = dest;
        vector<int>ans;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin() , ans.end());

        for(auto i : ans){
            cout<<i<<" , ";
        }
        cout<<endl;
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 1, 1);

    g.addEdge(3, 4, 1, 1);
    g.addEdge(0, 5, 1, 1);
    g.addEdge(5, 4, 1, 1);

    g.addEdge(0, 6, 1, 1);
    g.addEdge(6, 7, 1, 1);
    g.addEdge(7, 8, 1, 1);
    g.addEdge(8, 4, 1, 1);

    g.printAdjList();

    int src = 0;
    int dest = 4;

    g.shortestPathBFS(src, dest);

    return 0;
}