#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
  public:
  
    bool checkCyclicDirectedGraphUsingDfs(vector<int> adj[] , int src, unordered_map<int, bool> &visited,
                                          unordered_map<int, bool>& dfsVisited , int safenodes[])
    {
        // 1. Visited ko true mark krdo
        visited[src] = true;
        dfsVisited[src] = true;  
        // changes -> src safe nahi hai 
        safenodes[src] = 0;

        // 2. loop chalado neighbours  ke liye
        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                bool aageKaAns = checkCyclicDirectedGraphUsingDfs(adj , neighbour , visited , dfsVisited , safenodes);
                if(aageKaAns){
                    return true;
                }
            }
            if(visited[neighbour]== true && dfsVisited[neighbour] == true){
                return true; // cycle milgayi
            }
        }
        // yha galti karunga
        dfsVisited[src] = false;  // element hatate hue call se false mark karna tha // sort of back tracking
        safenodes[src] = true;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int, bool> visited, dfsVisited;
        
        int safenodes[V] = {0};
        
        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                checkCyclicDirectedGraphUsingDfs(adj , i , visited , dfsVisited , safenodes);
            }
        }
        
        for(int i=0 ; i<V; i++){
            if(safenodes[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};