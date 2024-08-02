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

//     void floydWarshal(int n)
//     {
//         vector<vector<int>> dist(n, vector<int>(n, 1000000));
//         // diagnol pr zero mark krdo
//         for (int i = 0; i < n; i++)
//         {
//             dist[i][i] = 0;
//         }
//         // graph k according distance insert krdia h
//         // jo bhi distances graph mein available hai unhe insert krlo
//         // not shortest
//         // this is distance from u->v
//         for (auto t : adjList)
//         {
//             for (auto nbr : t.second)
//             {
//                 int u = t.first;
//                 int v = nbr.first;
//                 int wt = nbr.second;
//                 dist[u][v] = wt;
//             }
//         }

//         // algo starts here
//         // helper ki help se saari possible permutation nikallo
//         for (int helper = 0; helper < n; helper++)
//         {
//             for (int src = 0; src < n; src++)
//             {
//                 for (int dest = 0; dest < n; dest++)
//                 {
//                     dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
//                 }
//             }
//         }

//         cout << "Printing distance array: " << endl;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout << dist[i][j] << ", ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     graph g;

//     g.addEdge(0, 1, 3, 0);
//     g.addEdge(0, 3, 5, 0);
//     g.addEdge(1, 0, 2, 0);

//     g.addEdge(1, 3, 4, 0);
//     g.addEdge(2, 1, 1, 0);
//     g.addEdge(3, 2, 2, 0);

//     g.printAdjList();
//     g.floydWarshal(4);
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

    void floydWarshal(int n)
    {
        // 1. creating vector of distance
        vector<vector<int>> distance(n, vector<int>(n, 10000));

        // 2. Mark diagonal zeros
        for (int i = 0; i < n; i++)
        {
            distance[i][i] = 0;
        }

        // 3. Also update in distance array the values from u->v from adjList.
        //    Because shortest path from u->v will be it's weight if not so it will be updated below
        //    By this we are filling the distance array with the values and later below the smallest 
        //    if possible will be updated
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;

                // 4. update the array
                distance[u][v] = wt;
            }
        }

        // 4. Now using helper we comapre and update distance array
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    // 5. Calculating distance2 with the help of helper, pehle helper pe gyi fir aage gyi
                    //    src -> helper -> destn
                    distance[src][dest] = min(distance[src][dest], distance[src][helper] + distance[helper][dest]);
                }
            }
        }

        cout << "Printing distance array: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << distance[i][j] << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, 3, 0);
    g.addEdge(0, 3, 5, 0);
    g.addEdge(1, 0, 2, 0);

    g.addEdge(1, 3, 4, 0);
    g.addEdge(2, 1, 1, 0);
    g.addEdge(3, 2, 2, 0);

    g.printAdjList();
    g.floydWarshal(4);
    return 0;
}