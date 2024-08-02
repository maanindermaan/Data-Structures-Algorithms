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
    void bfs(int src, unordered_map<int, bool> &visited)
    {
        // 1. Queue create
        queue<int> q;

        // 2. Queue mein push krna initial node(data) ko
        q.push(src);

        // 3. Uss node ko true mark krdena
        visited[src] = true;

        // 4. Jab tak queue na khali hojaye iterate krte raho
        while (!q.empty())
        {
            // 5. Top node nikaldo
            int frontNode = q.front();
            q.pop();
            // 6. Top node print krdo
            cout << frontNode << ", ";

            // 7. insert neighbours
            for (auto neighbour : adjList[frontNode])
            {
                // 8. Insert neighbours only if they are not visited
                if (!visited[neighbour])
                {
                    // 9. Inserting here
                    q.push(neighbour);

                    // 10. Those who have inserted mark -> TRUE
                    visited[neighbour] = true;
                }
            }
        }
    }

    // DFS
    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }

    // // For UNWEIGHTED GRAPH
    // unordered_map<int, list<int>> adjList;

    // void addEdge(int u, int v, bool direction)
    // {
    //     // direction = 0 -> undirected graph u->v and v->u (both)
    //     // direction = 1 -> directed graph u->v or v->u (given)
    //     // create an edge from u to v in every case whether direction 0 or 1
    //     adjList[u].push_back(v);
    //     if (direction == 0)
    //     {
    //         // undirected edge
    //         // create an edge from v to u
    //         adjList[v].push_back(u);
    //     }
    // }

    // void printAdjacencyList()
    // {
    //     for (auto node : adjList)
    //     {
    //         cout << node.first << "->";
    //         for (auto neighbour : node.second)
    //         {
    //             cout << neighbour << ",";
    //         }
    //         cout << endl;
    //     }
    // }

    // // FOR WEIGHTED
    // unordered_map<int, list<pair<int, int>>> adjList;

    // void addEdge(int u, int v, int weight, bool direction)
    // {
    //     // direction = 0 -> undirected graph
    //     // direction = 1 -> directed graph
    //     // create an edge from u to v
    //     adjList[u].push_back({v, weight});
    //     if (direction == 0)
    //     {
    //         // undirected edge
    //         // create an edge from v to u
    //         adjList[v].push_back({u, weight});
    //     }
    // }

    // void printAdjacencyList()
    // {
    //     for (auto node : adjList)
    //     {
    //         cout << node.first << "-> ";
    //         for (auto neighbour : node.second)
    //         {
    //             cout << "(" << neighbour.first << "," << neighbour.second << "), ";
    //         }
    //         cout << endl;
    //     }
    // }
};

int main()
{

    // 1. undirected edge input
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // cout << endl;
    // g.printAdjacencyList();

    // 2. directed input
    // Graph g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(0, 2, 1);
    // cout << endl;
    // g.printAdjacencyList();

    // 3. Weighted Directed input
    // g.addEdge(srcNode, destNode, weight, direction);
    // Graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(1, 2, 8, 1);
    // g.addEdge(0, 2, 6, 1);
    // cout << endl;
    // g.printAdjacencyList();

    // 4. Generic Unweighted
    // Graph<char> g;
    // g.addEdge('a', 'b', 0);
    // g.addEdge('b', 'c', 0);
    // g.addEdge('a', 'c', 0);
    // g.printAdjacencyList();


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
    // yeah wala step bas isiliye hai ki agar suppose ek node khatam hoagai lekin graph bacha hua hai toh 
    // mai uss particular node pe khada hoke jo ki mera loop traverse krega agar visited nahi toh call
    // mardunga dfs ki as simple as that
    cout << "Printing BFS Traversal: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }



    // The process of "backtracking" in DFS involves returning to a previously visited node after exploring all
    //  its unvisited neighbors. In the case of moving from node 6 to node 2, it's not exactly backtracking in
    //  the traditional sense, but rather returning to a previous node to explore a different branch of the 
    // graph. I apologize for any confusion caused by my earlier response.
    // 6. DFS
    cout << endl
         << "Printing DFS Traversal: " << endl;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    return 0;
}