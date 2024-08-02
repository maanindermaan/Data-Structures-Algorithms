// 1. Matrix method
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int > > adj(n+1 , vector<int>(n+1 , 0));

    for(int i=0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
} 

// 2. Adj list Method
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
return 0;
} 