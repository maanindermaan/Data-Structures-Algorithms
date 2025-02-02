#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution
{
    
    static bool mycmp(vector<int>&a , vector<int>&b){
        return a[2] < b[2];
    }
    
	public:
	
	int findParent(vector<int>&parent , int node){
	    if(parent[node] == node){
	        return node;
	    }
	    return parent[node] = findParent(parent , parent[node]); // path compression
	}
	
	void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
	    u = findParent(parent , u);
	    v = findParent(parent , v);
	    
	   // u ka parent u mien h stor krdiya
	    if(rank[u] < rank[v]){
	       // u chota hai 
	       parent[u] = v;
	       rank[v]++;
	    }
	    else{
	        parent[v] = u;
	        rank[u]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>parent(V);
        vector<int>rank(V, 0);
        
        // initialise parent, saare nodes individual component hongi
        for(int u = 0 ; u < V ; u++){
            parent[u] = u;
        }
        
        // making a linear DS from adj list
        // make edges linear DS
        vector<vector<int>>edges;
        for(int u=0 ; u<V ; u++){
            for(auto edge:adj[u]){
                int v = edge[0];
                int w = edge[1];
                edges.push_back({u , v , w});
            }
        }
        // sort it 
        sort(edges.begin() , edges.end() , mycmp);
        
        // because hume minimum spanning tree ka weight batado
        int ans = 0;
        // main ruly aaplying
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            u = findParent(parent , u);
            v = findParent(parent , v);
            
            if(u!=v){
                // union
                unionSet(u , v , parent , rank);
                ans+=w;
            }
        }
        return ans;
    }
};