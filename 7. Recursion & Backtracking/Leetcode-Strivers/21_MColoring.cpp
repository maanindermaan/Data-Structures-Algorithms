#include<iostream>
#include<array>
using namespace std;
int main(){

return 0;
}
class Solution{
public:
    
    bool isSafe(bool graph[101][101], int n, int col , int color[] ,int node){
        // check kro ki neighbour mein color hai ya nahi
        // har neighbour ke liye ek loop laga liya maine
        for(int k=0 ; k<n ; k++){
            // ab yeah check krdo ki kya vo node bhi present hai ya nahi using graph[][] == 1 then present
            // same node pe nai check karna uske neighbour ko check krna hai so node != k
            if(k != node && graph[k][node] == 1 && color[k] == col){
                return false;
            }
        }
        return true;
    }

    
    bool recursiveHelper(bool graph[101][101], int m, int n , int color[] , int node){
        // base case
        if(node == n){
            return true;
        }
        
        
        // har ek color ke liye call krdo (m -> colors) maine color ka naam 1 se ded diya
        for(int i=1 ; i<=m ; i++){
            if(isSafe(graph , n , i , color, node)){
                color[node] = i;
                
                if(recursiveHelper(graph , m , n , color , node+1)){
                    return true;
                }
                
                color[node] = 0;
            }
        }
        return false;
    }

    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(recursiveHelper(graph , m , n , color , 0)){
            return true;
        }
        return false;
    }
};