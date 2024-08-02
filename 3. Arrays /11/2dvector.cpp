#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<vector<int>>arr;

    // //   A
    // // vector<int>a{1,2,3};
    // // vector<int>b{4,5,6};
    // // vector<int>c{7,8,9};

    // // B
    // vector<int>a{1,2,3};
    // vector<int>b{4,5,6,7,8,9};
    // vector<int>c{10};

    // // outer vector mein vector<int> type ka data hi push hoga so here a b and c are pushed to outer vector
    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for(int i=0 ; i<arr.size() ; i++){
    //     // A
    //     // for(int j=0 ; j<arr[0].size() ; j++){
    //     // B
    //     for(int j=0 ; j<arr[i].size() ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    // **********OTHER METHOD***********
    int row =3;
    int col = 5;
    vector<vector<int>>arr(row/*Kitni rows chiyw*/ , vector<int>(col,0)); //vector<int>(col,0) -> har ek row mein chiye vector of int. Iss vector ka size hona chiye 5 or size = 0; 
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[i].size() ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}