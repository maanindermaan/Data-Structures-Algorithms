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

    // 3.
    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited,
                                          unordered_map<int, bool> dfsVisited)
    {
        // 1. Visited ko true mark krdo
        visited[src] = true;
        dfsVisited[src] = true;  

        // 2. loop chalado neighbours  ke liye
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                bool aageKaAns = checkCyclicDirectedGraphUsingDfs(neighbour , visited , dfsVisited);
                if(aageKaAns){
                    return true;
                }
            }
            if(visited[neighbour]== true && dfsVisited[neighbour] == true){
                return true;
            }
        }
        // yha galti karunga
        dfsVisited[src] = false;  // element hatate hue call se false mark karna tha // sort of back tracking
        return false;
    }
};

int main()
{
    // 3.
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    // g.addEdge(4, 0, 1); 

    g.printAdjacencyList();
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