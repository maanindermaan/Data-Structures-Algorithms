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

    void addEdge(int u, int v, int wt, bool direction) // if wt = 1, no need to include this
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

    void shortestDistDijkstra(int src, int n)
    {
        // 1. create distance arrray
        vector<int> dist(n, INT_MAX);

        // 2. Create a set
        set<pair<int, int>> st; //{nodeDistance , node};

        // 3. Src uthao uska distance 0 mark karo or use set mein daldo
        // initial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // 4. To find min element that is residing on begin of set, we have to use a iterator and we take
            // dereference operator to actually find value at that iterator.
            // Now this value is a pair of int, int because that is what we are inserting on begining of set
            // fetching smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // 5. now after using this remove this from set
            st.erase(st.begin());

            // 6. Trversing over neigbours of this node
            for (auto nbr : adjList[node])
            {
                // 7. agar ye jo nbr ka distance aayega agar yeah kam hai jo distance array mein pada hai
                // tabhi update hoga otherise nahi hoga
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // 8. I have to update the distance now
                    // now there may be two things
                    // (i) ya to jo distance update kerna hai uski entry set mein padi hui hai
                    // (ii) or ya toh ho sakta hai ki set mein nahi padi hogi
                    // mujhe makesure karna hai ki mai set mein bhi updatedDistance insert karu or
                    // distance wale array mein bhi updatedDistance insert karu or update karu.
                    // e.g. we update (14,1) -> (11,1)

                    // 9. I am going to find ki set ke andar purane wale distance ki entry padi hai k nahi padi
                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));

                    // 10. if found toh mai hatadunga update nahi karunga, hatake new entry insert karni padegi
                    if (result != st.end())
                    { // milgayi then remove
                        st.erase(result);
                    }
                    // 11. purani entry remove krdi toh new entry insert kro
                    // updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }
        cout << "printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }

    // practice
    void shortest(int src, int n)
    {
        vector<int> distance(n, INT_MAX);

        set<pair<int, int>> st; // {nodeDistance , node}

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            st.erase(st.begin());

            // nbr -> (node , weight/distance)
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < distance[nbr.first])
                {
                    auto result = st.find(make_pair(distance[nbr.first], nbr.first));

                    // if found remove it
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    // update distance and insert the update distance
                    distance[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(distance[nbr.first], nbr.first));
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            cout<<i<<" -> "<<distance[i]<<endl;
        }
    }
};

int main()
{
    graph g;
    g.addEdge(6, 3, 2, 1);
    g.addEdge(6, 1, 14, 1);
    g.addEdge(3, 1, 9, 1);
    g.addEdge(3, 2, 10, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 4, 15, 1);
    g.addEdge(4, 3, 11, 1);

    g.addEdge(6, 5, 9, 1);
    g.addEdge(4, 5, 6, 1);

    g.printAdjList();

    int src = 6;
    int n = 7;
    g.shortestDistDijkstra(src, n);

    return 0;
}