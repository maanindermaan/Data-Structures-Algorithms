#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

// GENERIC
template <typename T>

class Graph
{
public:
    // GENERIC
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // BFS
    void bfs(int source, unordered_map<int, bool> &visited)
    {
        // 1. Create a queue

        queue<int> q;

        q.push(source);

        // 2. Mark source true
        visited[source] = true;

        // 3. jab tak queue empty na ho jaye
        while (!q.empty())
        {
            // 4. extract top Node
            int top = q.front();
            q.pop();

            // 5. Print this element
            cout << top << " ";

            // 6. Extract neighbours of this top
            for (auto neighbour : adjList[top])
            {
                // 7. agar vo neighbour pehle nahi aaya hai toh
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }


    void dfs(int source, unordered_map<int, bool> &visited)
    {
        cout<<source<<" ";
        visited[source] = true;

        for(auto neighbour : adjList[source]){
            if(!visited[neighbour]){
                dfs(neighbour , visited);
            }
        }
    }
};

int main()
{
    // 5 and 6
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    g.printAdjacencyList();
    cout << endl;

    // 5. BFS
    unordered_map<int, bool> visited;
    // run a loop for all nodes
    // har node ko as a source location make hit marenge
    cout << "Printing BFS Traversal: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    cout<<endl;

    unordered_map<int, bool> visited2;
    cout << "Printing DFS Traversal: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    return 0;
}