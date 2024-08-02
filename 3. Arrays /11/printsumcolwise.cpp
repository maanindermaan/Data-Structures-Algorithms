#include <iostream>
using namespace std;

// ROW WISE
// void addRowWise(int arr[][4] , int rows , int cols){
//     for(int i=0 ; i<3 ; i++){
//         int sum = 0;
//         for(int j=0 ; j<4 ; j++){
//             sum = sum + arr[i][j];
//         }
//         cout<<sum<<endl;
//     }
// }

// COL WISE
void colSumArray(int arr[][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
}
int main()
{
    // ROW WISE
    // int arr[3][4];
    // int rows = 3;
    // int cols = 4;

    // for(int i=0 ; i<3 ; i++){
    //     for(int j=0 ; j<4 ; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0 ; i<3 ; i++){
    //     for(int j=0 ; j<4 ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // addRowWise(arr , rows , cols);

    // COL WISE
    int arr[3][3];
    int row = 3;
    int col = 3;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    colSumArray(arr, row, col);
}