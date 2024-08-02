#include<iostream>
#include<set>
#include<list>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    // we have to make adjLIST here by ourself
    int shortestDistDijkstra(int src, int n , unordered_map<int , list<pair<int , int>>>&adjList , int& distanceThreshold)
    {
        // 1. create distance arrray
        vector<int> dist(n, INT_MAX);

        // 2. Create a set
        set<pair<int, int>> st; //{nodeDistance , node};

        // 3. Src uthao uska distance 0 mark karo or use set mein daldo
        // initial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        // ye code src se destn jaane wali saari nodes ke corresponding minimum shortest distance nikal ke rakh dega
        // lekin mujhe saara ni chiye

        int reachableCities = 0; // stores cities at most having distanceThreshold distance

        while (!st.empty())
        {
            // 4. To find min element that is residing on begin of set, we have to use a iterator and we take
            // dereference operator to actually find value at that iterator.
            // Now this value is a pair of int, int because that is what we are inserting on begining of set
            // fetching smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;



            // becuase mai 0 se 0 nahi jana chahta
            if(node != src && nodeDistance <= distanceThreshold){
                reachableCities++;
            }



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
        return reachableCities;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int , list<pair<int , int>>>adjList;
        for(auto edge : edges){
            int&u = edge[0];
            int&v = edge[1];
            int&w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        // mujhe har node ke corrponding same kaam krna hai 
        int city = 0;
        int minReachableCities = INT_MAX;

        // hume har cities ke corresponding saare counts chahiye jo ki distanceThreshold jitna distance away ho

        for(int u=0 ; u<n ; u++){
            int reachableCitiesCount = shortestDistDijkstra(u , n , adjList , distanceThreshold);
            // agar sirf < rakhunga toh city mein 0 hota update ni ho paata ye 3 se so we took <=
            if(reachableCitiesCount <= minReachableCities){
                minReachableCities = reachableCitiesCount;
                // sath hi mai ans store karta jaunga city mein
                city = u;
            }
        }
        return city;
    }
};