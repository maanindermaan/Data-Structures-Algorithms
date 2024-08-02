// There are n customers and m shops in
// HackerMall. The th customer wishes to purchase items of types [customer, customeri2, ..
// customerial, and the th shop sells items of types [shopin, shopiz, .., shopikl. The number of items of each type in a shop is unlimited, so several customers can buy items of the same type from a shop.
// A customer is considered as served if all the types of items the customer wishes to purchase are available in the open shops. Initially, all shops are closed. Find the maximum number of customers who can be served by the mall if at most 2 shops are opened to serve the customers.
// Example
// Consider n = 2, p = 2, and customer = [I1, 2], [1,
// 5I). Also, m = 3, k = 4, and shop = [11, 2, 3, 417, 12, 3,
// 4, 5], [1, 2, 4, 51].
// If the first and second shops are opened:
// ﻿﻿The first customer can be served all items from the first shop.
// ﻿﻿The second customer buys item type 1 from shop 1 and item type 5 from shop 2.
// Both the customers can be served. Thus, the answer is 2.

// Function Description
// Complete the function countMaximumCustomers in the editor below.
// countMaximumCustomers has the following parameters:
// int customer[n][p]: the types of items each customer wishes to purchase
// int shop[m][k]: the types of items offered by each shop
// Returns
// int: the maximum number of customers that can be served
// Constraints:
// ﻿﻿1 ≤ ns 105
// ﻿﻿1 sms 105
// ﻿﻿15k≤7
// ﻿﻿15p57
// ﻿﻿1 ≤ customer[ill] ≤ 7
// ﻿﻿1 ≤ shop[iffil ≤ 7

// Write a function countMaximumCustomers having parameters vector of vector of int customer vector of vector of int shop

// Solution :-> this is not correct code this is an approximated code
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int countMaximumCustomers(vector<vector<int>>& customer, vector<vector<int>>& shop) {
    int max_customers = 0;
    int m = shop.size();
    
    for (int bitmask = 0; bitmask < (1 << m); ++bitmask) {
        vector<set<int>> selected_shops;
        for (int i = 0; i < m; ++i) {
            if (bitmask & (1 << i)) {
                selected_shops.push_back(set<int>(shop[i].begin(), shop[i].end()));
            }
        }
        
        int served_customers = 0;
        for (const auto& c : customer) {
            bool can_be_served = true;
            for (int item : c) {
                bool found = false;
                for (auto& s : selected_shops) {
                    if (s.count(item)) {
                        s.erase(item);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    can_be_served = false;
                    break;
                }
            }
            if (can_be_served) {
                served_customers++;
            }
        }
        
        max_customers = max(max_customers, served_customers);
    }
    
    return max_customers;
}

int main() {
    vector<vector<int>> customers = {{1, 2}, {1, 5}};
    vector<vector<int>> shops = {{1, 2, 3, 4}, {1, 2, 4, 5}};
    
    int result = countMaximumCustomers(customers, shops);
    cout << result << endl; // This will print the maximum number of customers that can be served
    
    return 0;
}

