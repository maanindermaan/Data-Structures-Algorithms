// SPIRAL PRINT
#include<iostream>
#include<vector>
using namespace std;

void spiralPrint(vector<vector<int>> arr) {
    int m = arr.size();  // Number of rows
    int n = arr[0].size();  // Number of columns
    int totalElements = m * n;

    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = m - 1;
    int startingCol = 0;

    int count = 0;
    while (count < totalElements) {
        // Printing Starting Row
        for (int i = startingCol; i <= endingCol; i++) {
            cout << arr[startingRow][i] << " ";
            count++;
        }
        startingRow++;

        // Printing Ending Column
        for (int i = startingRow; i <= endingRow; i++) {
            cout << arr[i][endingCol] << " ";
            count++;
        }
        endingCol--;

        // Printing Ending Row
        if (count < totalElements) {
            for (int i = endingCol; i >= startingCol; i--) {
                cout << arr[endingRow][i] << " ";
                count++;
            }
            endingRow--;
        }

        // Printing Starting Column
        if (count < totalElements) {
            for (int i = endingRow; i >= startingRow; i--) {
                cout << arr[i][startingCol] << " ";
                count++;
            }
            startingCol++;
        }
    }
}

int main() {
    vector<vector<int>> arr{{1, 2, 3, 4, 5, 6},
                            {7, 8, 9, 10, 11, 12},
                            {13, 14, 15, 16, 17, 18},
                            {19, 20, 21, 22, 23, 24},
                            {25, 26, 27, 28, 29, 30}};
    spiralPrint(arr);
    return 0;
}
