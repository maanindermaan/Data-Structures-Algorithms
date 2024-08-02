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
    bool checkCyclicUsingBfs(int src, unordered_map<int, bool> &visited)
    {
        // 1. Create a queue and map of parent
        queue<int> q;
        unordered_map<int, int> parent;

        // 2. Push initial node to queue and mark parent(initially -1) and visited true
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        // 3. Traverse till queue is not empty
        while (!q.empty())
        {
            // 4. Extract frontnode node
            int frontNode = q.front();
            q.pop();

            // 5. Extract neighbours of frontNode
            for (auto nbr : adjList[frontNode])
            {
                // 6. If it is not visited
                if (!visited[nbr])
                {
                    // 7. Push neighbour if not visited into queue and mark visited true and update parent
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                // 8. (i) Node already visited hai and (ii) jis node se aarhe ho vo is node ka parent nahi hai
                // else if(visited[nbr] && frontNode != parent[nbr]){ why not this
                else if (visited[nbr] && nbr != parent[frontNode])
                {
                    // 9. cycle present
                    return true;
                }
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
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    // g.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicUsingBfs(i, visited);
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