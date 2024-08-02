// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>
// using namespace std;

// // in this code we have 1 base indexing so we are starting from 1 so imarginary earlier was at -1 now at 0
// int main()
// {
//     int x, y, n; // Intitally x and y are the size of array/grid, 15*8 and n is number of towers presented 
//     cin >> x >> y >> n;
//     int t = n;
//     vector<int> rowC; // row Coordinates
//     vector<int> colC; // col Coordinates 

//     // initial imaginary pushing into the coordinates array
//     rowC.push_back(0);
//     colC.push_back(0);

//     // input store krlia i.e. coordinates of tower
//     while (t--)  // a and b are coordinates of towers
//     {
//         int a, b;
//         cin >> a >> b;
//         rowC.push_back(a);
//         colC.push_back(b);
//     }

//     // size of 2D grid (ending index we have to insert)
//     // ending row and col ke baad ek or imagibnary tower rakhlia hai
//     // additional imaginary towers are added at the ending row and column coordinates.
//     rowC.push_back(x + 1);
//     colC.push_back(y + 1);

//     sort(rowC.begin(), rowC.end());
//     sort(colC.begin(), colC.end());

//     int maxLen = INT_MIN;
//     for (int i = 1; i < rowC.size(); i++)
//     {
//         int a = rowC[i - 1];
//         int b = rowC[i];

//         maxLen = max(maxLen, b - a - 1);
//     }

//     int maxWidth = INT_MIN;
//     for (int i = 1; i < colC.size(); i++)
//     {
//         int a = colC[i - 1];
//         int b = colC[i];

//         maxWidth = max(maxWidth, b - a - 1);
//     }

//     cout << "answer is " << maxLen * maxWidth << endl;

//     return 0;
// }




// practice
#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
int main(){
    int x , y , n; // x and y are size of grid and n is number of towers
    cin>>x>>y>>n;

    vector<int>rowC;
    vector<int>colC;

    int t = n;

    while(t--){
        // taking coordinates of tower as input
        int a , b;
        cin>>a>>b;
        rowC.push_back(a);
        colC.push_back(b);
    }

    // take one extra element for imaginary tower
    rowC.push_back(x+1);
    colC.push_back(y+1);

    // sort them
    sort(rowC.begin() , rowC.end());
    sort(colC.begin() , colC.end());

    // intution
    int maxLength = INT_MIN;
    for(int i=1 ; i<rowC.size() ; i++){
        int a = rowC[i-1];
        int b = rowC[i];

        maxLength = max(maxLength , b-a-1);
    }

    int maxWidth = INT_MIN;
    for(int i=1 ; i<colC.size() ; i++){
        int a = colC[i-1];
        int b = colC[i];

        maxWidth = max(maxWidth , b-a-1);
    }

    cout<<"The answer is :- "<<maxWidth * maxLength;
return 0;
}