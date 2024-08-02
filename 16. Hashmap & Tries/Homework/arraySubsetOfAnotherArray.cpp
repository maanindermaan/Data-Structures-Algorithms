#include <iostream>
using namespace std;

bool isSubset(unordered_map<int,int>& mapping , int arr1[] , int arr2[] , int n , int m){
    // 2. Create a flag
    bool flag = false;

    // 3. Check that whther every element of arr2 lies in arr1
    for(int i=0 ; i<m ; i++){
        // if(mapping[arr2[i]] != 0){
        //     mapping[arr2[i]]--;
        //     flag = true;
        // }
        // 4. element found
        if(mapping.find(arr2[i]) != mapping.end()){
            mapping[arr2[i]]--;
            flag = true;
        }
        // 5. If not found
        else{
            flag = false;
        }
    }
    // 6. Return result
    if(flag == true){
        return true;
    }
    return false;
}

int main()
{
    int arr1[] = {11,7,1,13,21,3,7,3};
    int arr2[] = {11,3,7,1,7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // 1. store arr1 into map
    unordered_map<int,int> mapping;

    for(int i=0 ; i<n ; i++){
        mapping[arr1[i]]++;
    }

    cout<<isSubset(mapping , arr1 , arr2 , n , m);
    return 0;
}