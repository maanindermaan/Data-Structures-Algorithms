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

    void topologicalSortUsingBFS(int n, vector<int> &ans)
    {
        // 0. Abhi toh mai indegree nikalrha hu reduce (subtract) bad mein karunga
        // 1. Create a queue
        queue<int> q;
        unordered_map<int, int> indegree; // {number , indegree}

        // 2. indegree nikaldo
        for (auto i : adjList)
        { // {int , list<int>}
            // 3. Pehle source nikallo e.go 1->2,3 (adj list). this source is 1 and neighbour are 2,3 stored in adj list
            int src = i.first;
            // for(auto i : adjList[src]){
            for (auto nbr : i.second)
            {
                // 4. i want to increment the indegree of neighbour
                indegree[nbr]++;
            }
        }

        // 5. Put all nodes inside queue which has indegree 0 (pehle se 0 thi toh e.g. source node)
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 6. BFS logic to reduce the indegree
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);
            // or we can do count++ to calculate number of nodes in topological sort for cycle detection

            // 7. Reduce the indegree of nbr attached to node
            // reduce the indegree for the neighbour of this fNode as it is popped now
            for (auto nbr : adjList[fNode])
            {
                // 8. reducing by 1 from nbrs
                indegree[nbr]--;

                // 9. Agar -1(uper subtract) karne ke baad indegree 0 hojaye toh check karlo ek baar
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
    void topologicalSortUsingBFS(int n, vector<int> &ans)
    {
        // 1. Create queue and unordered map of indegree
        queue<int>q;
        unordered_map<int , int> indegree; // { int , int } -> {number , or uski indegree}

        // 2. Find the indegree
        for(auto i : adjList){ // {int , list<int>}
            int src = i.first;

            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }

        // 3. Push into queue which has indegree 0
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // 4. reduce the indegree and push into queue
        while(!q.empty()){
            int front = q.front();
            q.pop();

            // insert this front into ans
            ans.push_back(front);

            // reduce the indegree for the neighbour of this front as it is popped now
            for(auto nbr : adjList[front]){
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{

    Graph<int> g;
    // n -> number of nodes in graph
    int n = 8;

    // 1. No cycle valid T.S.
    // g.addEdge(2, 4, 1);
    // g.addEdge(2, 5, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(5, 3, 1);
    // g.addEdge(3, 7, 1);
    // g.addEdge(6, 7, 1);
    // g.addEdge(7, 0, 1);
    // g.addEdge(7, 1, 1);

    // 2. Cycle present valid T.S.
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);

    g.printAdjacencyList();
    cout << endl;

    vector<int> ans;
    // connected or disconnected
    g.topologicalSortUsingBFS(n, ans);

    if (ans.size() == n)
    {
        cout << "It is a valid topo sort" << endl;
    }
    else
    {
        cout << "Cycle Present or Invalid topo sort " << endl;
    }

    cout << "Printing Topological Sort using BFS: " << endl;
    for (auto i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}