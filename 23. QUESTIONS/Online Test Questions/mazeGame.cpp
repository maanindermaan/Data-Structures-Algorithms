// A game contains a maze represented as a graph with n vertices
// numbered 1 to n and m bidirectional edges numbered 1 to m. The ith edge
// connects endpoint1[il and endpoint2[i]. It takes edgeLength[il units of time to traverse the th edge. Each vertex / will disappear at time ti] and will not reappear. If a visit occurs at the same time the vertex disappears, the vertex cannot be reached.
// The game starts at vertex 1 and time 0. Find the earliest visit time for each vertex, starting from vertex 1. If a vertex cannot be reached, the arrival time is - 1.
// Example:
// In the graph below, the vertices are labeled [vertex number/time to disappear].

// Graph there are four nodes node 1 : 1/1 node 2 : 2/2 node 3 : 4/9 node 4 : 3/7    Now from node 1 to node 2 weight is 2 from node 2 to node 3 weight is 1 from 3 to 4 eight is 3 and from 4 to 1 weight is 5. 

// n=4 m=4
// t = [1, 2, 7, 9]
// endpoint1 = [1, 2, 3, 4]
// endpoint2 = (2, 4, 1, 3]
// edgeLength = [2, 1, 5, 3]
// ﻿﻿Arrive at vertex 1 at time = 0 with time to traverse = 0. The vertex disappears at time 1. Visit time = 0.
// ﻿﻿For vertex 2: It takes edgeLength = 2 to traverse from 1 to 2. Arrive at vertex 2 at time 2, just as the vertex disappears. It is impossible to visit vertex 2. Visit time = - 1.
// ﻿﻿From vertex 1 to vertex 3: It takes edgeLength =
// 5 to traverse between 1 and 3. Arrival time is 0 + 5 = 5, which is prior to t[3] = 7. Visit time = 5.
// ﻿﻿Move from vertex 3 to vertex 4: It takes edgeLength| 3 to traverse between 4 and
// 3. Arrival time is 5 + 3 = 8, which is prior to t[4] =
// 9. The visit time = 8.
// The answer array is [0, -1, 5, 8]
// Function Description
// Complete the function mazeGame in the editor below.
// mazeGame has the following parameter(s):

// int t[n] an array of integers, the ith vertex goes away at t[if, 1-based index
// int endpoint1 [m]: vertex number of one end of an edge[i], 1-based index
// int endpoint2[m]: vertex number of the other end edge[i], 1-based index
// int edgeLength[m]: edgeLength[i] is the time it takes to traverse edge[i], 1-based index Returns:
// int[m]: the arrival times at each vertex i or -1 if the visit not possible
// 4
// Constraints
// ﻿﻿1 ≤ n,m ≤ 300000
// ﻿﻿1 ≤ tlis 3×1014 or tli] = 1
// ﻿﻿1 s endpoint1 [i], endpoint2[i] < n
// ﻿﻿endpoint1 [i] + en}/point2[i]
// ﻿﻿1 s edgeLengthli s 10°


// Write a function vector of long mazeGame with parameters vector of long t vector of int endpoint1 , vector of int endpoint 2 and vector of int edge length 
// In c++


// Solution :-> APPROXIMATED
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<long> mazeGame(vector<long> t, vector<int> endpoint1, vector<int> endpoint2, vector<int> edgeLength) {
    int n = t.size();
    int m = endpoint1.size();
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        graph[endpoint1[i]].emplace_back(endpoint2[i], edgeLength[i]);
        graph[endpoint2[i]].emplace_back(endpoint1[i], edgeLength[i]);
    }
    
    vector<long> arrivalTimes(n + 1, -1);
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    
    pq.emplace(0, 1);
    arrivalTimes[1] = 0;
    
    while (!pq.empty()) {
        long time = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();
        
        if (time > t[currentVertex - 1]) {
            continue; // Skip if vertex has disappeared
        }
        
        for (auto& neighbor : graph[currentVertex]) {
            int neighborVertex = neighbor.first;
            int edgeWeight = neighbor.second;
            long newTime = time + edgeWeight;
            
            if (newTime < t[neighborVertex - 1] && (arrivalTimes[neighborVertex] == -1 || newTime < arrivalTimes[neighborVertex])) {
                arrivalTimes[neighborVertex] = newTime;
                pq.emplace(newTime, neighborVertex);
            }
        }
    }
    
    return arrivalTimes;
}

int main() {
    vector<long> t = {1, 2, 9, 7};
    vector<int> endpoint1 = {1, 2, 3, 4};
    vector<int> endpoint2 = {2, 4, 1, 3};
    vector<int> edgeLength = {2, 1, 5, 3};
    
    vector<long> result = mazeGame(t, endpoint1, endpoint2, edgeLength);
    
    for (int i = 1; i <= result.size(); ++i) {
        cout << "Vertex " << i << ": Arrival time = " << result[i] << endl;
    }
    
    return 0;
}



