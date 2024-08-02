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

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        // while returning, store the node in stack
        cout << "Pushing " << src << endl;
        ans.push(src);
    }

    void shortestpathDFS(int dest, stack<int> topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbr : adjList[0])
        { // dist or wt is the same thing
            if (dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {

            int topElement = topoOrder.top();
            topoOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto nbr : adjList[topElement])
                {
                    if (dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing Ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> " << dist[i] << endl;
        }
    }

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        // while returning, store the node in stack
        cout << "Pushing " << src << endl;
        ans.push(src);
    }

    void shortestpathDFS(int dest, stack<int> topoOrder, int n)
    {
        // 1. Create a distance vector
        vector<int> distance(n, INT_MAX);

        // 2. Find out the source element and perform operations
        int src = topoOrder.top();
        topoOrder.pop();

        // 3. Check whether the distance calculated here is smaller than distance having in distance vector
        for (auto nbr : adjList[0])
        {
            if (distance[0] + nbr.second < distance[nbr.first])
            {
                distance[nbr.first] = distance[0] + nbr.second;
            }
        }

        // 4. Now find for rest of the elements from 0
        while (!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            // vrna INT_MAX + 10 se thodina compare karunga distance vector ko
            if (distance[topElement] != INT_MAX)
            {
                for (auto nbr : adjList[topElement])
                {
                    if (distance[topElement] + nbr.second < distance[nbr.first])
                    {
                        distance[nbr.first] = distance[topElement] + nbr.second;
                    }
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            cout<<i<<" -> "<<distance[i];
            cout<<endl;
        }
    }
};

int main()
{
    graph g;

    int n = 5;
    g.addEdge(0, 1, 5, 0);
    g.addEdge(0, 2, 3, 0);
    g.addEdge(2, 1, 2, 0);
    g.addEdge(1, 3, 3, 0);
    g.addEdge(2, 3, 5, 0);
    g.addEdge(2, 4, 6, 0);
    g.addEdge(4, 3, 1, 0);

    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    // stack mein topoOrder aagya hoga
    g.topoSortDfs(0, visited, topoOrder);

    int dest = 3;

    g.shortestpathDFS(dest, topoOrder, n);

    return 0;
}