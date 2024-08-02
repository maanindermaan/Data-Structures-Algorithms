// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool cmp(pair<int, int> a, pair<int, int> b)
// {
//     double ratio1 = ((1.0) * a.first) / a.second;
//     double ratio2 = ((1.0) * b.first) / b.second;
//     return ratio1 > ratio2; // jiska ratio bada hoga vo vector ke andar pehle aajayega 
// }

// int main()
// {
//     int val[] = {60, 100, 120};
//     int wt[] = {10, 20, 30};
//     int n = 3;
//     int capacity = 50;

//     // value or wt ko single vector ke andar insert karlia, or saare data ko sort krlia basis on aapke 
//     // val / wt ka ratio
//     vector<pair<int, int>> data;
//     for (int i = 0; i < n; i++)
//     {
//         data.push_back({val[i], wt[i]});
//     }

//     sort(data.begin(), data.end(), cmp);
//     int totalValue = 0;
//     // check each items k entire itm lelu ya frraction lu
//     for (int i = 0; i < n; i++)
//     {
//         // aaapne har ek item ko uhaya, 
//         // I agar aap entire item ko include kr sakte hai toh entire ko include
//         // karne ke liye 2 step perform kiye
//         // 1. Aapne total value + ki uss item ki  
//         // 2. Aapne capacity ko increment krdiya by decrementing the item weight
//         // below is error of type casting  
//         pair<int, int> item = data[i];
//         int itemValue = item.first;
//         int itemWeight = item.second;
//         // entire inclusioon wala case
//         if (itemWeight <= capacity)
//         {
//             // add kardo value ko
//             totalValue += itemValue;
//             // update krdo capacity ko
//             capacity = capacity - itemWeight;
//         }
//         // II Aap fractional le sakte ho manlo poori item ki capacity nahi bachi hai 
//         else
//         {
//             // fraction include krdo
//             // update value
//             double ratio = ((1.0) * itemValue) / itemWeight;
//             int valueToAdd = ratio * capacity;
//             totalValue += valueToAdd;

//             // udpate capacity;
//             // kamm capacity bachi thi or saari ki saari aapne use krli
//             // we have utilised the whole capacity i.e why we are coming to this else case
//             capacity = 0;
//         }
//     }
//     cout << "Answer is: " << totalValue << endl;
//     return 0;
// }




// practice
#include<iostream>
#include<vector>
using namespace std;

bool cmp(pair<int ,int>a , pair<int , int>b){
    double ratio1 = ((1.0) * a.first) / a.second;
    double ratio2 = ((1.0) * b.first) / b.second;

    return ratio1 > ratio2;
}

int main(){
    int val[] = {60,100,120};
    int weight[] = {10,20,30};
    int n = 3;
    int capacity = 50;

    // 1. push this weight and val into a vector of pair of int
    vector<pair<int , int>>arr;
    for(int i=0 ; i<n ; i++){
        arr.push_back({val[i] , weight[i]});
    }

    // 2. Sort this vector in ascending order
    sort(arr.begin() , arr.end() , cmp);

    // 3. take some more variables

    int totalValue = 0;

    // 4. Start the for loop to traverse all the values

    for(int i=0 ; i<n ; i++){
        pair<int , int> item = arr[i];

        int itemVal = item.first;
        int itemWight = item.second;

        // 5. If there is capacity avaialble then it can come inside
        if(itemWight <= capacity){
            totalValue += itemVal;
            capacity = capacity - itemWight;
        }
        else{
            double ratio = ((1.0)*itemVal) / itemWight;
            double value = ratio * capacity;

            totalValue += value;

            capacity = 0;
        }
    }

    cout<<totalValue;
return 0;
}