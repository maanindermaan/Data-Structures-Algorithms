// TARZAN'S ALGORITHM
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

    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> vis)
    {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            // nbr aapka parent ke equal na ho, jis bhi node ke liye aap kaam karrhe ho uska parent na ho,
            // agar parent hi nahi hua toh parent ke uper mai kabhi bhi traversal krne wala hu nahi
            // continue matlab yha se bhar nikal jao go to next itertion
            if (nbr == parent)
            {
                continue;
            }

            if (!vis[nbr])
            {
                // jao aage ka case explore krke laao
                // dfs call maaro
                findBridges(nbr, src, timer, tin, low, vis);
                // low update kar dena dfs call se vapis aate hue
                low[src] = min(low[src], low[nbr]); // hum jaise low ko update krdete the
                // check for bridge
                // if (low[nbr] > low[src])
                if (low[nbr] > tin[src])
                {
                    cout << nbr << "--" << src << " is a bridge" << endl;
                }
            }
            else // low[child] <= tin[parent]
            {
                // node is visited and not a parent
                // low update means koi or rasta
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main()
{
    graph g;

    // 1.
    g.addEdge(0, 1, 1);

    g.addEdge(1, 2, 1);

    g.addEdge(2, 0, 1);

    g.addEdge(1, 6, 1);

    g.addEdge(3, 1, 1);

    g.addEdge(1, 4, 1);

    g.addEdge(3, 5, 1);

    g.addEdge(4, 5, 1);

    // 2.
    // g.addEdge(0,1,1);

    // g.addEdge(0,2,1);

    // g.addEdge(2,1,1);

    // g.addEdge(0,3,1);

    // g.addEdge(3,4,1);

    int n = 7;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    g.findBridges(0, -1, timer, tin, low, vis);

    return 0;
}




// PRACTICE
// TARZAN'S ALGORITHM
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
    unordered_map<int, list<int> > adjList;

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

    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> visited)
    {
        // 1. Jo node krli traverse use true mark krdo
        visited[src] = true;

        // 2. tin or low bhi update krdo. Humne tin or low ko isliye liya hai because hmare paas har node ki
        //    corresponding values hai tin or low vector ki
        tin[src] = timer;
        low[src] = timer;

        // 3. Ab mai timer ko bada rha hu taki jab mai next node pe jau toh mai tin or low mein timer update kr
        //    saku
        timer++;

        // 4. Ab nbr of src pe traverse kro
        for (auto nbr : adjList[src])
        {
            // 5. Agar nbr == -1 aajaye toh yeah iteration skip kardeta hai
            // Inside the loop, the condition if(nbr == parent) is checked. The purpose of this condition is
            // to skip the processing for the neighbor node if it is the same as the parent node.

            // In summary, when parent is -1, the continue statement does not affect the execution flow of the
            //  loop, and all neighbors of the current node are processed as usual.

            // Specifically, it's used to handle the case when the depth-first search (DFS) algorithm is
            // traversing back from a child node to its parent node.
            if (nbr == parent)
            {
                continue;
            }
            // 6. Agar visited nahi hai toh simple hai hume kuch conditions check krni hai or call marni hai
            //    DFS ki
            if (!visited[nbr])
            {
                // 7. Recursive call mardo
                findBridges(nbr, src, timer, tin, low, visited);

                // 8. low[parent]/ low[src] ko update krke dekho, if possible toh
                low[src] = min(low[nbr], low[src]);

                // 9. Check for bridge condition
                if (low[nbr] > tin[src])
                {
                    cout << nbr << " -> " << src << endl;
                }
            }
            // 10. visited hai and low[nbr] <= tin[src]
            else
            {
                // 11. low[parent]/ low[src] ko update krke dekho
                //     Becuase try to understand hum iss case mein bhi src pe khade hoke check krte hai from
                //     its child
                low[src] = min(low[nbr], low[src]);
            }
        }
    }
};

int main()
{
    graph g;

    // 1.
    g.addEdge(0, 1, 1);

    g.addEdge(1, 2, 1);

    g.addEdge(2, 0, 1);

    g.addEdge(1, 6, 1);

    g.addEdge(3, 1, 1);

    g.addEdge(1, 4, 1);

    g.addEdge(3, 5, 1);

    g.addEdge(4, 5, 1);

    // 2.
    // g.addEdge(0,1,1);

    // g.addEdge(0,2,1);

    // g.addEdge(2,1,1);

    // g.addEdge(0,3,1);

    // g.addEdge(3,4,1);

    int n = 7;
    int timer = 0;
    vector<int> tin(n);
    vector<int>low(n);
    unordered_map<int, bool> vis;
    g.findBridges(0, -1, timer, tin, low, vis);

    return 0;
}