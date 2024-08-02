// The neural network of a virtual world is represented as a connected directed graph data structure, g. It has n nodes numbered from 1 to n, and n-1 edges, where the th edge connects node g_from[i] to g_ toli].
// Select any node as root then reverse as many edges as necessary to have all edges flowing down, that is, away from the root. Choose a root that requires the minimum number of changes and report that number of changes.
// Example
// Given, g_ nodes = 4, g_from = [1, 2, 3], and g_to =
// [4, 4, 4]. The tree can be visualized as:

// Node having values 1 , 2 and 3 are pointing towards 4. 

// One of the optimal strategies is to select node 2 as root and invert edges 1 to 4 and 3 to 4. This the minimum number of edges to be inverted is 2. 

// Hence the answer is 2. 

// Function Description
// Complete the function getMininversions in the editor below.
// getMininversions takes the following arguments:
// int g_ nodes: the number of nodes in the graph int g_from[g edges]: the starting end of the directed edges
// int g_to[g_edges]: the ending node of the directed edges
// Returns
// int: the minimum number of edges that must be inverted
// Constraints
// ﻿﻿2 ≤ g nodes s 105
// ﻿﻿1 ≤ g_fromlil, g_toli] < g_ nodes
// ﻿﻿g_from[i] + g_to[i]


// Solution :-> APPROXIMATED CODE NOT CORRECT CODE
#include <iostream>
#include <vector>

using namespace std;

int getMinInversions(int g_nodes, vector<int> g_from, vector<int> g_to) {
    vector<vector<int>> graph(g_nodes + 1);
    for (int i = 0; i < g_from.size(); ++i) {
        graph[g_from[i]].push_back(g_to[i]);
    }
    
    vector<bool> visited(g_nodes + 1, false);
    
    int root = 1;
    int minInversions = INT_MAX;
    
    for (int i = 1; i <= g_nodes; ++i) {
        int inversions = 0;
        if (!visited[i]) {
            vector<int> stack;
            stack.push_back(i);
            
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                visited[node] = true;
                
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        stack.push_back(neighbor);
                        ++inversions;
                    }
                }
            }
            
            if (inversions < minInversions) {
                minInversions = inversions;
                root = i;
            }
        }
    }
    
    return minInversions;
}

int main() {
    int g_nodes = 4;
    vector<int> g_from = {1, 2, 3};
    vector<int> g_to = {4, 4, 4};
    cout << getMinInversions(g_nodes, g_from, g_to) << endl;  // Output: 2
    
    return 0;
}
