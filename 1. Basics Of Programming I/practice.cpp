#include <iostream>
using namespace std;
int main()
{
    // 27. Floyd's Traingle Pattern
    int rowCount;
    cout<<"Enter number of rows : ";
    cin>>rowCount;
    // PART - I
    for(int row = 1 ; row<= rowCount ; row++){
        // part 1
        for(int col = 1 ; col<=row ; col++){
            cout<<"*";
        }

        // part 2 Spaces
        for(int col = 1 ; col<= (2*rowCount) - (2*row) + 1 ; col++){
            cout<<" ";
        }

        // part 3
        for(int col = 1 ; col<=row ; col++){
            cout<<"*";
        }
        cout<<endl;
    }

    // PART - II
    for(int row = 1 ; row<= rowCount ; row++){
        // part 1
        for(int col = 1 ; col<=rowCount - row + 1 ; col++){
            cout<<"*";
        }

        // part 2 Spaces
        for(int col = 1 ; col<= (2*row) - 1 ; col++){
            cout<<" ";
        }

        // part 3
        for(int col = 1 ; col<=rowCount - row + 1 ; col++){
            cout<<"*";
        }
        cout<<endl;
    }
}