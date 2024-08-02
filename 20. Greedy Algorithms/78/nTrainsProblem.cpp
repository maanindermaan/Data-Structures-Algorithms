// // Activity Selection Problem , One meetings in a room , N trains in a platform ko findout kr sakte ho Using GREEDY
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // ye bta rha hai ki ending time ke hisab se sort krna hai
// bool cmp(pair<int, int> a, pair<int, int> b)
// {
//     return a.second < b.second;
// }

// int solve(int n, int arr[], int dept[])
// {
//     // iske andar saara data daldo 
//     vector<pair<int, int>> data;
//     for (int i = 0; i < n; i++)
//     {
//         data.push_back({arr[i], dept[i]});
//     }

//     sort(data.begin(), data.end(), cmp);

//     int cnt = 1; // ek train toh aayegi hi hai, pehli train it is
//     cout << data[0].first << ", " << data[0].second << endl; // jo jo time include hue hai unhe print karwalo
//     int lastDept = data[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (data[i].first >= lastDept) // agar curr wali train ka arrival time agar >= hai last wali train ke dept time ke
//         {
//             // current train can be included
//             cnt++;
//             // last dept ko update bhi toh karna hai(previously included train)
//             lastDept = data[i].second;
//             cout << data[i].first << ", " << data[i].second << endl; // jo jo time include hue hai unhe print karwalo
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     int n = 4;
//     int arr[] = {5, 8, 2, 4};
//     int dept[] = {7, 11, 6, 5};

//     int ans = solve(n, arr, dept);
//     cout << "Answer is:  " << ans << endl;

//     return 0;
// }



// practice
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int solve(int n, int arr[], int dept[])
{
    // 1. Make a pair of vector of arrival , departure
    vector<pair<int , int>>vec;

    for(int i=0 ; i<n ; i++){
        vec.push_back({dept[i] , arr[i]});
    }

    // 2. Sort it out
    sort(vec.begin() , vec.end());

    int count = 1; //pehli train to aa hi gyi hai

    int lastDeptTime = vec[0].first;
    for(int i=0 ; i<n ; i++){
        int arrivalTime = vec[i+1].second;

        if(lastDeptTime<=arrivalTime){
            count++;
            lastDeptTime = vec[i].first;
        }        
    }
    return count;
}

int main()
{
    int n = 4;
    int arr[] = {5, 8, 2, 4};
    int dept[] = {7, 11, 6, 5};

    int ans = solve(n, arr, dept);
    cout << "Answer is:  " << ans << endl;

    return 0;
}