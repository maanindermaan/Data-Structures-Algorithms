#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
public:
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

    // 1. BFS
    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited,
                                      unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aagekaans = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aagekaans == true)
                {
                    return true;
                }
            }

            if (visited[nbr] && dfsVisited[nbr])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // 1.
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 4;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    // g.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if (ans == true)
                break;
        }
    }

    if (ans == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

    return 0;
}