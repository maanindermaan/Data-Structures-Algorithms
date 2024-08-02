#include<iostream>
using namespace std;
int main(){
return 0;
}

class Solution{
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
	        parent[u] = v;
	        rank[u]++;
	    }
	}

    int makeConnected(int n, vector<vector<int>>& connections) {
        // 1. need to find NOCC(Number of Connected Components), and 
        // 2. number of extra edges
        vector<int>parent(n);
        vector<int>rank(n, 0);
        
        // 3. initialise parent, saare nodes individual component hongi
        for(int u = 0 ; u < n ; u++){
            parent[u] = u;
        }

        int extraEdges = 0;

        // 4. Iterate over given array to find u and v
        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];

            // 5. u and v ke parents unhi mein store krdiye
            u = findParent(parent , u);
            v = findParent(parent , v);

            // 6. dono agar unequal hai to union kardo
            if(u!=v){
                unionSet(u,v,parent,rank);
            }
            else{
                // 7. dono ke parents equal hogye
                extraEdges++;
            }
        }

        // 8. finding number of connected components from parent array
        int nocc = 0;
        for(int i =0 ; i < n ; i++){
            if(parent[i] == i){
                nocc++;
            }
        }
        int ans = nocc-1; // no of operations / cables needed
        return extraEdges >= ans ? ans : -1;
    }
};