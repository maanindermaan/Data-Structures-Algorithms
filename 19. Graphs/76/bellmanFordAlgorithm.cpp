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
//     unordered_map<int, list<pair<int, int>>> adjList;

//     void addEdge(int u, int v, int wt, bool direction)
//     {
//         // direction = 1 -> undirected graph
//         // direction => 0 -> directed graph;
//         adjList[u].push_back({v, wt});
//         if (direction == 1)
//         {
//             adjList[v].push_back({u, wt});
//         }
//     }

//     void printAdjList()
//     {
//         for (auto i : adjList)
//         {
//             cout << i.first << "-> ";
//             for (auto j : i.second)
//             {
//                 cout << "(" << j.first << ", " << j.second << "), ";
//             }
//             cout << endl;
//         }
//     }

//     void bellmanFordAlgo(int n, int src)
//     {
//         // assuming directed weighted graph
//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;
//         // n-1 relaxation step
//         for (int i = 0; i < n - 1; i++)
//         {
//             // for all edges
//             for (auto t : adjList)   // adjList -> {node -> (node , weight)}
//             {
//                 for (auto nbr : t.second) // u->v ki edge hai
//                 {
//                     int u = t.first;
//                     int v = nbr.first;
//                     int wt = nbr.second;
//                     if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
//                     {
//                         dist[v] = dist[u] + wt;
//                     }
//                 }
//             }
//         }

//         // to check for -ve cycle
//         // ek baar step ko aur run krdo
//         bool negativeCycle = false;
//         for (auto t : adjList)
//         {
//             for (auto nbr : t.second)
//             {
//                 int u = t.first;
//                 int v = nbr.first;
//                 int wt = nbr.second;
//                 if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
//                 {
//                     // agar update hue toh true
//                     negativeCycle = true;
//                     break;
//                 }
//             }
//         }

//         if (negativeCycle == true)
//             cout << "-ve cycle present";
//         else
//             cout << "-ve cycle absent";

//         cout<<endl;

//         cout << "printing dist array: ";

//         cout << endl;
//         for (auto i : dist)
//             cout << i << " ";
//     }
// };

// int main()
// {
//     graph g;

//     g.addEdge(0, 1, -1, 0);
//     g.addEdge(0, 2, 4, 0);
//     g.addEdge(1, 2, 3, 0);

//     g.addEdge(1, 3, 2, 0);
//     g.addEdge(2, 4, 2, 0);
//     g.addEdge(3, 1, 1, 0);

//     g.addEdge(3, 2, 5, 0);
//     g.addEdge(4, 3, -3, 0);

//     g.printAdjList();
//     g.bellmanFordAlgo(5, 0);

//     return 0;
// }





























// PRACTICE
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

    void addEdge(int u, int v, int wt, bool direction)
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

    void bellmanFordAlgo(int n, int src)
    {
        // 1. create a distance array of n size, initalized with infinity
        vector<int> dist(n, INT_MAX);

        // 2. Assign 0 at src. for initial start
        dist[src] = 0;

        // 3. Perform n-1 relaxation step
        for (int i = 0; i < n - 1; i++)
        {
            // 4. Traverse over adjList -> {node -> (node , weight)}
            for (auto t : adjList)
            {
                // 5. Now iterate over pair of this adjList
                for (auto nbr : t.second)
                {
                    // 6. Find u , v and wt on that node
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    // 7. Checking whether the distance from curr node including wt. is smaller than the
                    //    distance at that position. we are going from u->v
                    //    distance we are comparing that is dist[u] distance of curr node, if it becomes
                    //    INT_MAX we will not be able to compare with other node where we are going (destn)
                    //    becuase this INT_MAX + wt on that node will be out of bound so we ignore this case
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        // 8. If it is smaller update it simple we are updating in loop for n-1 times
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // 9. Now we are done with n-1 times passes and answer would have been found till now and if we do one
        //    more time for addtional pass and if value doesnot changes then there is not cycle but if it
        //    changes then cycle found

        // 10. repeat same process one more time
        bool negativeCycle = false;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    // 11. Now if it this condition is true then cycle presents we simple turns the flag ONN
                    negativeCycle = true;
                    break;
                }
            }
        }

        if (negativeCycle)
        {
            cout << "Negative Cycle Found";
        }
        else
        {
            cout << "No negative cycle found";
        }

        // 12. Printing the final result

        cout << endl;

        cout << "printing dist array: ";

        cout << endl;
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 0);
    g.addEdge(1, 2, 3, 0);

    g.addEdge(1, 3, 2, 0);
    g.addEdge(2, 4, 2, 0);
    g.addEdge(3, 1, 1, 0);

    g.addEdge(3, 2, 5, 0);
    g.addEdge(4, 3, -3, 0);

    g.printAdjList();
    g.bellmanFordAlgo(5, 0);

    return 0;
}