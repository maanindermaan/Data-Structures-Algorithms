#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
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

    // void topologicalSortUsingDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    // {

    //     visited[src] = true;

    //     for (auto neighbour : adjList[src])
    //     {
    //         if (!visited[neighbour])
    //         {
    //             topologicalSortUsingDFS(neighbour, visited , ans);
    //         }
    //     }
    //     // while returning, store node in stack
    //     ans.push(src);
    // }

    void topologicalSortUsingDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        // 1. initial source ko true mark krdo
        visited[src] = true;

        // 2. ab iterate krte raho source ke nieghbours pe that are in adjList
        for(auto neighbour : adjList[src]){
            // 3. Agar visited nahi hai toh hi mai jaunga
            if(!visited[neighbour]){
                // 4. Recursive call mardo
                topologicalSortUsingDFS(neighbour , visited , ans);
            }
        }
        // 5. While returning push back into stack
        ans.push(src);
    }
};

int main()
{

    // 1. undirected edge input
    Graph<int> g;
    int n = 8;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    cout << endl;
    g.printAdjacencyList();

    unordered_map<int, bool> visited;
    stack<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topologicalSortUsingDFS(i, visited, ans);
        }
    }

    cout << "Top Sort: " << endl;
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}