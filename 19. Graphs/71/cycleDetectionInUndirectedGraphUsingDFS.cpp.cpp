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

    // 2.
    bool checkCyclicUsingDfs(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src]) // src se neighbour ja sakte ho
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src); // to nbr ka parent src hogya
                if (checkAageKaAns == true)
                    return true;
            }
            else if (visited[nbr] && nbr != parent)
            {
                // cycle present
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // 2.
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 0, 0);

    g.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicUsingDfs(i, visited, -1);
            if (ans == true)
                break;
        }
    }

    if (ans == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

}