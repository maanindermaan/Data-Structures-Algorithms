#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minRefulStations(int target, int startFuel, vector<vector<int>> stations) //{distance , fuel}
{
    // 1. Declare useful variables
    int stops = 0;
    int index = 0;
    int distanceTravelled = 0;
    int fuel = startFuel;

    // 2. Make a maxHeap to store max FUEL , distance
    priority_queue<pair<int , int>>maxHeap; //{fuel , distance} -> because we need maxFuel 

    while(true){
        // 3. Push all elements in range of fuel to maxHeap that will arrange according to fuel left
        while(index<stations.size()){
            if(stations[index][0] <= distanceTravelled + fuel){
                maxHeap.push(make_pair(stations[index][1] , stations[index][0]));
            }
            else{
                break;
            }
            index++;
        }

        // 4. Update distanceTravelled and fuel
        distanceTravelled += fuel;
        fuel = 0; // fuel already added above in ditance travelled

        // 5. Check if target reached
        if(distanceTravelled >= target){
            break;
        }

        // 6. If we can't reach upto there or anynode 
        if(maxHeap.empty()){
            stops = -1;
            break;
        }

        // 7. If it can reach but not reached upto target update fuel and distance
        pair<int , int> temp = maxHeap.top();
        maxHeap.pop();

        fuel = distanceTravelled - temp.second + temp.first;
        distanceTravelled = temp.second;

        // 8. Update the stops
        stops++;
    }
    return stops;
}

int main()
{
    vector<vector<int>> stations{{10, 60},
                                 {20, 30},
                                 {30, 30},
                                 {60, 40}}; // {distance , fuel capacity}

    int startFuel = 10;
    int target = 100;

    cout << "Minimum refueling stations are : " << minRefulStations(target, startFuel, stations);
    return 0;
}






// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int minRefulStations(int target, int startFuel, vector<vector<int>> stations)
// {
//     int stops = 0;
//     int distanceTravelled = 0;
//     int i = 0;
//     int fuel = startFuel;
//     priority_queue<pair<int, int>> maxHeap; // {fuel , distance}. Prioirty is with FUEL.

//     while (true)
//     {
//         while (i < stations.size())
//         {
//             // 1. Push all stations within the reach with my current fuel levels from my current position or distance
//             if (stations[i][0] <= distanceTravelled + fuel)
//             {
//                 maxHeap.push(make_pair(stations[i][1], stations[i][0]));
//             }
//             else
//             {
//                 break;
//             }
//             // 2. Har ek element ko push krne ke bad next ke liye check kro
//             ++i;
//         }

//         // 3. Jitna fuel hai utna travel kro aap
//         distanceTravelled = distanceTravelled + fuel;
//         fuel = 0;

//         // 4. REACHED
//         if (distanceTravelled >= target)
//         {
//             break;
//         }

//         // 5. If no fuel station to reach
//         if (maxHeap.empty())
//         {
//             stops = -1;
//             break;
//         }

//         // 6. NOT REACHED
//         // Refuel and readjust distance and fuel based on distance travelled and fuel used till that station
//         auto top = maxHeap.top();
//         fuel = (distanceTravelled - top.second) + top.first;
//         distanceTravelled = top.second;
//         maxHeap.pop();
//         ++stops;
//     }
//     return stops;
// }

// int main()
// {
//     vector<vector<int>> stations{{10, 60},
//                                  {20, 30},
//                                  {30, 30},
//                                  {60, 40}}; // {distance , fuel capacity}

//     int startFuel = 10;
//     int target = 100;

//     cout << "Minimum refueling stations are : " << minRefulStations(target, startFuel, stations);
//     return 0;
// }





