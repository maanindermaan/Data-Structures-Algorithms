// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <set>
// #include <limits.h>
// using namespace std;

// class graph
// {
// public:
//     unordered_map<int, list<int>> adjList;

//     void addEdge(int u, int v, bool direction)
//     {
//         // direction = 1 -> undirected graph
//         // direction => 0 -> directed graph;
//         adjList[u].push_back(v);
//         if (direction == 1)
//         {
//             adjList[v].push_back(u);
//         }
//     }

//     void dfs1(int src, stack<int> &s, unordered_map<int, bool> &vis)
//     {
//         vis[src] = true;

//         for (auto nbr : adjList[src])
//         {
//             if (!vis[nbr])
//             {
//                 dfs1(nbr, s, vis);
//             }
//         }
//         // vapis jate hue fo toplogical odering
//         s.push(src);
//     }

//     void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew)
//     {
//         visited[src] = true;
//         cout << src << ", ";

//         for (auto nbr : adjNew[src])
//         {
//             if (!visited[nbr])
//             {
//                 dfs2(nbr, visited, adjNew);
//             }
//         }
//     }

//     int countSCC(int n)
//     {
//         stack<int> s;
//         unordered_map<int, bool> visited;

//         // 1. find topo ordering
//         for (int i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs1(i, s, visited);
//             }
//         }

//         // 2. reverse all edges
//         unordered_map<int, list<int>> adjNew;

//         for (auto t : adjList)
//         {
//             for (auto nbr : t.second)
//             {
//                 int u = t.first;
//                 int v = nbr;
//                 // v-> u insert
//                 // reversing here
//                 adjNew[v].push_back(u);
//             }
//         }

//         // 3. traversse using DFS
//         int count = 0;
//         unordered_map<int, bool> visited2;

//         while (!s.empty())
//         {
//             int node = s.top();
//             s.pop();
//             if (!visited2[node])
//             {
//                 cout << "Printing " << count + 1 << "th SCC: ";
//                 dfs2(node, visited2, adjNew);
//                 cout << endl;
//                 count++;
//             }
//         }

//         return count;
//     }
// };

// int main()
// {
//     graph g;

//     g.addEdge(0,1,0);

//     g.addEdge(1,2,0);

//     g.addEdge(2,3,0);

//     g.addEdge(3,0,0);

//     g.addEdge(2,4,0);

//     g.addEdge(4,5,0);

//     g.addEdge(5,6,0);

//     g.addEdge(6,4,0);

//     g.addEdge(6,7,0);

//     int ans = g.countSCC(8);
//     cout << "Number of SCC: " << ans << endl;

//     return 0;
// }

// PRACICE
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
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 1 -> undirected graph
        // direction => 0 -> directed graph;
        adjList[u].push_back(v);
        if (direction == 1)
        {
            adjList[v].push_back(u);
        }
    }

    // topological sorting
    void dfs1(int src, unordered_map<int, bool> &visited1, stack<int> &s)
    {
        // 3. mark visited of src true
        visited1[src] = true;

        // 4. Iterate over neighbours and call recursively
        for (auto nbr : adjList[src])
        {
            while (!visited1[nbr])
            {
                dfs1(nbr, visited1, s);
            }
        }
        // 5. Vapis jate hue push krdo stack mein
        s.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &visited2 , unordered_map<int, list<int>>& adjListNew)
    {
        // 12. mark visited of src true
        visited2[src] = true;

        cout<<" , "<<src;

        // 13. Iterate over neighbours and call recursively
        for (auto nbr : adjListNew[src])
        {
            while (!visited2[nbr])
            {
                dfs2(nbr, visited2 , adjListNew);
            }
        }
    }

    int countSCC(int n)
    {
        // I Topological Sort
        // 1. make a stack and map
        stack<int> s;
        unordered_map<int, bool> visited1;

        // 2. call for dfs1 function and findout topological sort
        for (int i = 0; i < n; i++)
        {
            if (!visited1[i])
            {

                dfs1(i, visited1, s);
            }
        }

        // II Reverse edges
        // 6. Make new adjList that will store reversed edges elements
        unordered_map<int, list<int>> adjListNew;

        // 7. Now insert those elements into this list and reverse that all edges 
        for (auto t : adjList)
        { // {int , list<int>}
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;

                // 8. This inserts reversed list
                adjListNew[v].push_back(u);
            }
        }

        // III DFS , print and count nodes
        // 9. Now we will first extract element from stack which are in topological order and then we will
        //    apply dfs on then handling the disconnected component cases and increase the count and print it

        unordered_map<int , bool>visited2;
        int count = 0;

        while(!s.empty()){
            // 10. Extract top value of s
            int node = s.top();
            s.pop();

            // 11. Agar visited nahi toh bhejdo
            if(!visited2[node]){
                cout<<"Printing the "<<count+1<<" SCC : -> ";
                dfs2(node , visited2 , adjListNew);
                // 14. Increase the count;
                cout<<endl;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, 0);

    g.addEdge(1, 2, 0);

    g.addEdge(2, 3, 0);

    g.addEdge(3, 0, 0);

    g.addEdge(2, 4, 0);

    g.addEdge(4, 5, 0);

    g.addEdge(5, 6, 0);

    g.addEdge(6, 4, 0);

    g.addEdge(6, 7, 0);

    int ans = g.countSCC(8);
    cout << "Number of SCC: " << ans << endl;

    return 0;
}
