#include <iostream>
using namespace std;
int main()
{

    return 0;
}
class Solution
{
public:
    // key array se sabse minimum value nikal ke dedo ye dhyaan rakhna ki vo MST mein add na hui ho , MST true na ho
    // mujhe isse key array ka index miljayega jiski sabse kamm value hai or yehi index aapka node ko signify karta hai
    int getMinValueNode(vector<int> &key, vector<int> &mst)
    {
        int temp = INT_MAX;
        int index = -1; // represent actual node having minimum value
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < temp && mst[i] == false)
            {
                temp = key[i];
                index = i;
            }
        }
        return index;
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<int> mst(V, false); // to keep track which all nodes are added into mst
        vector<int> parent(V, -1); // stores final MST relations

        key[0] = 0;

        while (true)
        {
            // step 1 : Find the value of u
            int u = getMinValueNode(key, mst);
            if (u == -1)
                break;

            // step 2 : Mark MST[u] = true
            mst[u] = true;

            // step 3 : Process all adjacent nodes to u
            for (auto edge : adj[u])
            {   // jis node pe aap khade ho uske corresponding saari aajengi
                // u se v tak ek edge jarhi hai
                int v = edge[0];
                int w = edge[1];
                if (mst[v] == false && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        // find sum of W's of the edges of the MST
        int sum = 0;
        for (int u = 0; u < parent.size(); u++)
        {
            if (parent[u] == -1)
                continue;
            for (auto edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                if (v == parent[u])
                {
                    sum += w;
                }
            }
        }
        return sum;
    }
};