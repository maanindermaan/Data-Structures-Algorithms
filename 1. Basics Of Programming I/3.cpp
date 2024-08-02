// PATTERNS
#include<iostream>
using namespace std;
int main(){

// 1. Solid rectange pattern
// Outer for loop - row observe
//     for(int row=0 ; row<3 ; row++){
//         // inner forloop - col observe
//         for(int col=0 ; col<5 ; col++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }
// 1. Solid rectange pattern
// ************WE DONOT USE THIS ULTA PULTA ROW COL SO USE STANDARD AS ABOVE **************
// Outer for loop - col observe 
//     for(int col=0 ; col<5 ; col++){
//         // inner forloop - row observe
//         for(int row=0 ; row<3 ; row++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }


// 2. Solid Square Pattern
//     for(int row=0 ; row<4 ; row++){
//         for(int col=0 ; col<4 ; col++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }


// 3. Predifned square pattern
// int n;
// cin>>n;
//     for(int row=0 ; row<n ; row++){
//         for(int col=0 ; col<n ; col++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }


// 4. Hollow rectange pattern
//     for(int row=0 ; row<3 ; row++){
//         // First or Last row -> print 5*
//         if(row==0 || row==2){
//             for(int col=0 ; col<5 ; col++){
//                 cout<<"*"<<" ";
//             }
//         }
//         // Remaining Middle rows
//         else{
//             // First star
//             cout<<"*"<<" ";
//             // Spaces
//             for(int i=0 ; i<3 ; i++){
//                 cout<<" "<<" ";
//             }
//             // Last star
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }


// 5. Generic Hollow rectange pattern
// int rowCount , colCount;
// cin>>rowCount;
// cin>>colCount;
//     for(int row=0 ; row<rowCount ; row++){
//         // First or Last row -> print 5*
//         if(row==0 || row==rowCount-1){
//             for(int col=0 ; col<colCount ; col++){
//                 cout<<"*"<<" ";
//             }
//         }
//         // Remaining Middle rows
//         else{
//             // First star
//             cout<<"*"<<" ";
//             // Spaces
//             for(int i=0 ; i<colCount-2 ; i++){
//                 cout<<" "<<" ";
//             }
//             // Last star
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
// }


// 6. Generic Half Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<row+1 ; col++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
//     }


// 6. Generic Inverted Half Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<rowCount-row ; col++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
//     }



// 7. Generic Numeric Half Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<row+1 ; col++){
//             cout<<col+1<<" "; 
//         }
//         cout<<endl;
//     }



// 7. Generic Inverted Numeric Half Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<rowCount-row ; col++){
//             cout<<col+1<<" "; 
//         }
//         cout<<endl;
//     }




// 8. Generic FULL Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<rowCount-(row+1) ; col++){
//             cout<<" "; 
//         }
//         for(int col = 0 ; col<row+1 ; col++){
//             cout<<"*"<<" "; 
//         }
//         cout<<endl;
//     }



// 9. Generic Inverted FULL Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<row ; col++){
//             cout<<" "; 
//         }
//         for(int col = 0 ; col<rowCount-row ; col++){
//             cout<<"*"<<" "; 
//         }
//         cout<<endl;
//     }



// 10. Generic Numeric FULL Pyramid
// int rowCount;
// cin>>rowCount;
//     for(int row = 0 ; row<rowCount ; row++){
//         // Spaces
//         for(int col = 0 ; col<(rowCount+1)-row ; col++){
//             cout<<" "; 
//         }
//         // Numbers
//         for(int col = 1 ; col<row+2 ; col++){
//             cout<<col; 
//         }
//         cout<<endl;
//     }


// 10. Generic Numeric FULL Pyramid Palindrome Patten SIMPLE
// int rowCount;
// cin>>rowCount;

// for(int row=0 ; row<rowCount ; row++){
//     // Spaces
//     for(int col=0; col<rowCount-row ; col++){
//         cout<<" ";
//     }
//     // Numbers in ascending order
//     for(int col=1 ; col<row+1 ; col++){
//         cout<<col;
//     }
//     // Numbers in descending order
//     for(int col = row ; col>1 ; col--){
//         cout<<col;
//     }
//     cout<<endl;
// }




// // 11. Generic Numeric FULL Pyramid Palindrome Patten COMPLEX
//     int rows;
//     cout << "Enter the number of rows: ";
//     cin >> rows;

//     int currentNum = 1;

//     for (int i = 1; i <= rows; i++) {
//         // Print spaces
//         for (int col = 1; col <= rows - i; col++) {
//             cout << " ";
//         }

//         // Print numbers in ascending order
//         for (int col = 1; col <= i; col++) {
//             cout << currentNum++;
//         }

//         // Print numbers in descending order
//         for (int col = 0; col < i; col++) {
//             cout << --currentNum;
//         }

//         cout << std::endl;
//     }



// 12. Generic Numeric FULL Pyramid Palindrome Patten COMPLEX(For this case only we are considering that the pyramid starts from row 1)
//  int rowCount;
//     cout << "Enter the number of rows: ";   
//     cin >> rowCount;

//     for (int row = 1; row <= rowCount; row++) {
//         // Print spaces
//         for (int col = 1; col <= rowCount - row; col++) {
//             cout << " ";
//         }

//         // Print numbers in increasing order0
//         for (int col = row; col <= (row*2)- 1; col++) { // or (row+row -1)
//             cout << col;
//         }

//         // Print numbers in decreasing order
//         for (int col = row + row - 2; col >= row; col--) {
//             cout << col;
//         }

//         cout << endl;
//     }







// 13. Numeric Hollow Full Pyramid
//  int rowCount;
//     cout << "Enter the number of rows: ";   
//     cin >> rowCount;

//     for (int row = 1; row <= rowCount; row++) {
//         // Print spaces
//         for (int col = 1; col <= rowCount - row; col++) {
//             cout << " ";
//         }

//         // For 1st and Last Row
//         if(row==1 || row==rowCount){
//             for(int col=1 ; col<=row ; col++){
//                 cout<<col<<" "<<" ";
//             }
//         }

//         // For middle ones
//         else{
//             // First digit
//             cout<<1;
//             // Middle Spaces
//             for(int i=1 ; i<row ; i++){
//                 cout<<" "<<" ";
//             }
//             // Last digit
//             cout<<row;
//         }
        

//         cout << endl;
//     }






// 14. SOLID DIAMOND
// int rowCount;
// cout<<"Enter number of rows : "<<endl;
// cin>>rowCount;
//     // FULL PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<rowCount-(row+1) ; col++){
//             cout<<" "; 
//         }
//         for(int col = 0 ; col<row+1 ; col++){
//             cout<<"*"<<" "; 
//         }
//         cout<<endl;
//     }
//     // INVERTED PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<row ; col++){
//             cout<<" "; 
//         }
//         for(int col = 0 ; col<rowCount-row ; col++){
//             cout<<"*"<<" "; 
//         }
//         cout<<endl;
//     }



// // 15. HOLLOW DIAMOND
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
//     // FULL PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<rowCount-(row+1) ; col++){
//             cout<<" "; 
//         }
//         if(row==0){
//             cout<<"*";
//         }
//         else{
//             // First Star
//         cout<<"*";
//         // SPACES between
//         for(int col=0 ; col<row ; col++){
//             cout<<" "<<" ";
//         }
//         // Last Star
//         cout<<"*";
//         }
        

//         cout<<endl;
//     }
//     // INVERTED PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         for(int col = 0 ; col<row ; col++){
//             cout<<" "; 
//         }
//         for(int col = 0 ; col<rowCount-row ; col++){
//             cout<<"*"<<" "; 
//         }
//         cout<<endl;
//     }





// 15. HOLLOW DIAMOND
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
//     // FULL PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         // Spaces
//         for(int col = 0 ; col<rowCount-(row+1) ; col++){
//             cout<<" "; 
//         }
//         // Stars
//         for(int col=0 ; col<(2*row)+1; col++){
//             // First or last character
//             if(col==0 || col==2*row){
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     // INVERTED PYRAMID
//     for(int row = 0 ; row<rowCount ; row++){
//         // Spaces
//         for(int col = 0 ; col<row ; col++){
//             cout<<" "; 
//         }
//         // Stars
//         for(int col = 0 ; col<2*rowCount-(row*2)-1 ; col++){
//             if(col==0 || col==2*rowCount-(row*2)-2){
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }



// 15.
// int rowCount;
//     cout<<"Enter number of rows : "<<endl;
//     cin>>rowCount;
//     // full pyramid
//     for(int row=1 ; row<=rowCount ; row++){
//         // spaces
//         for(int col = 1 ; col<=rowCount-row ; col++){
//             cout<<" ";
//         }
//         // middle part
//         if(row == 1){
//             cout<<"*";
//         }
//         else{
//             cout<<"*";
//             // middle spaces
//             for(int col = 1 ; col<= (row*2)-3 ; col++){
//                 cout<<" ";
//             }
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     // inverted full pyramid
//     //     // INVERTED PYRAMID
//     for(int row = 1 ; row<=rowCount ; row++){
//         // Spaces
//         for(int col = 2 ; col<=row ; col++){
//             cout<<" "; 
//         }
//         // Stars
//         if(row == rowCount){
//             cout<<"*";
//         }
//         else{
//             cout<<"*";
//             // middle spaces
//             for(int col=1 ; col<= ((2*rowCount) - (2*row) -1) ; col++){
//                 cout<<" ";
//             }
//             cout<<"*";
//         }
//         cout<<endl;
//     }




// 16. FLIPPED SOLID DIAMOND 
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;

// // FOR FIGURE I
// for(int row=0 ; row<rowCount ; row++){
//     // For Part (i)
//     for(int col=0; col<rowCount-row ; col++){
//         cout<<"*";
//     }
//     // For Part (ii)
//     for(int col=0 ; col<(2*row)+1 ; col++){
//         cout<<" ";
//     }
//     // For Part (iii)
//     for(int col=0; col<rowCount-row ; col++){
//         cout<<"*";
//     }
//     cout<<endl;
// }

// // FOR FIGURE II
// for(int row=0 ; row<rowCount ; row++){
//     // For Part (i)
//     for(int col=0; col<row+1 ; col++){
//         cout<<"*";
//     }
//     // For Part (ii)
//     for(int col=0 ; col<2*rowCount-(2*row)-1 ; col++){
//         cout<<" ";
//     }
//     // For Part (iii)
//     for(int col=0; col<row+1 ; col++){
//         cout<<"*";
//     }
//     cout<<endl;
// }




// 17. Fancy Pattern 2
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;

// // FOR FIGURE I
// for(int row=0 ; row<rowCount ; row++){
//     for(int col=0; col<row+1 ; col++){
//         cout<<row+1;
//         if(col!=row){
//             cout<<"*";
//         }
//     }
//     cout<<endl;
// }  

// // FOR FIGURE I
// for(int row=0 ; row<rowCount ; row++){
//     for(int col=0; col<rowCount-row ; col++){
//         cout<<rowCount-row;
//         if(col!=rowCount-row-1){
//             cout<<"*";
//         }
//     }
//     cout<<endl;
// }  





// 18. Alphabet Palindrome 
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;

// for(int row=0 ; row<rowCount ; row++){
//     for(int col=0; col<row+1 ; col++){
//         cout<<col+1<<" ";
//     }
//     for(int col=row; col>0 ; col--){
//         cout<<col<<" ";
//     }
//     cout<<endl;
// }  

// **********************OR*************************

// for(int row=0 ; row<rowCount ; row++){
//     int col;//Initialised outside
//     for( col=0; col<row+1 ; col++){
//         cout<<col+1<<" ";
//     }
//     col = col-1; // this decreases the value of last updated column (col=row) is now not needed
//     for( ; col>0 ; col--){
//         cout<<col<<" ";
//     }
//     cout<<endl;
// }  
// ************ CONVERTING NUMERIC TO ALPHABET ***************
// for(int row=0 ; row<rowCount ; row++){
//     int col;//Initialised outside
//     for( col=0; col<row+1 ; col++){
//         int ans = col+1;
//         char ch = ans + 'A' - 1;// -1 becuase before -1 it was starting from B intially
//         cout<<ch<<" ";
//     }
//     col = col-1; // this decreases the value of last updated column (col=row) is now not needed
//     for( ; col>0 ; col--){
//         int ans = col;
//         char ch = ans + 'A' - 1;
//         cout<<ch<<" ";
//     }
//     cout<<endl;
// } 

// *****************************OOOOOOOORRRRRRRRRR********************************
//     int rowCount;
//     cout<<"Enter number of rows dickhead : ";
//     cin>>rowCount;

//     for(int row = 1 ; row<=rowCount ; row++){
//         for(int col=1 ; col<=row ; col++){
//             int ans = col;
//             char ch = ans + 'A' -1;
//             cout<<ch<<" ";
//         }
//         for(int col=row ; col>1 ; col--){
//             int ans = col;
//             char ch = ans + 'A' - 2;
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }














// 19. Hollow Full Pyramid 
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // For Spaces
//     for(int col=0; col<rowCount-(row+1) ; col++){
//         cout<<" ";
//     }
//     // For Stars
//     // First and Last row
//     if(row==0 || row==rowCount-1){
//         for(int col=0 ; col<row+1 ; col++){
//             cout<<"*"<<" ";
//         }
//     }
//     // For middle ones
//     else{
//         cout<<"*";
//         for(int col=0 ; col<(2*row)-1; col++){
//             cout<<" ";
//         }
//         cout<<"*";
//     }
//     cout<<endl;
// }






// 20. Numeric Hollow Half Pyramid
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // First and Last row
//     if(row==0 || row==rowCount-1){
//         for(int col=0 ; col<row+1 ; col++){
//             cout<<col+1<<" ";
//         }
//     }
//     // For middle ones
//     else{
//         cout<<1;
//         for(int col=0 ; col<(2*row)-1; col++){
//             cout<<" ";
//         }
//         cout<<row+1<<" ";
//     }
//     cout<<endl;
// }






// 21. Numeric Hollow Inverted Half Pyramid
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // First row
//     if(row==0){
//         for(int col=0 ; col<rowCount-row ; col++){
//             cout<<col+1<<" ";
//         }
//     }
//     // Last row
//     else if(row==rowCount-1){
//         cout<<rowCount<<" ";
//     }
//     // For other ones
//     else{
//         cout<<row+1;
//         for(int col=0 ; col<(2*rowCount)-(2*row+1)-2; col++){
//             cout<<" ";
//         }
//         cout<<rowCount<<" ";
//     }
//     cout<<endl;
// }


/////////////// OoOOOOOOORRRRRRRRRRR///////////////////////
// 21. Numeric Hollow Inverted Half Pyramid
    // int rowCount;
    // cout<<"Enter number of rows : ";
    // cin>>rowCount;
    
    // for(int row = 1 ; row <= rowCount ; row++){
    //     if(row == 1){
    //         for(int col=1 ; col<= rowCount - row + 1 ; col++){
    //             cout<<col<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     else if(row == rowCount){
    //         cout<<rowCount<<" ";
    //         cout<<endl;
    //     }
    //     else{
    //         // first digit
    //         cout<<row;
    //         // spaces
    //         for(int col=1 ; col<= rowCount-row-1 ; col++){
    //             cout<<"  ";
    //         }
    //         // last digit
    //         cout<<" ";
    //         cout<<rowCount;
    //         cout<<endl;
    //     }
    // }






// 22. Numeric Palindrome Equailateral Pyramid
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // Section I (Spaces)
//     for(int col=0 ; col<rowCount-(row+1) ; col++){
//         cout<<" "<<" ";
//     }
//     // Section II (Triangle-I)
//     for(int col=0 ; col<row+1 ; col++){
//         cout<<col+1<<" ";
//     }
//     // Section III (Triangle-II)
//     for(int col=row ; col>0 ; col--){
//         cout<<col<<" ";
//     }
//     cout<<endl;
// }

// OR
// int rowCount;
//     cout<<"Enter number of rows : ";
//     cin>>rowCount;
//     for(int row=0 ; row<rowCount ; row++){
//         // spaces
//         for(int col = 1 ; col<= rowCount-row ; col++){
//             cout<<" ";
//         }
//         // left part
//         for(int col = 1 ; col<=row ; col++){
//             cout<<col;
//         }
//         // right part
//         for(int col = row ; col>1 ; col--){
//             cout<<col-1;
//         }
//         cout<<endl;
//     }












// 23. Fancy Pattern #1
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // Section I (Stars)
//     for(int col=0 ; col<(2*rowCount-(row+2)) ; col++){
//         cout<<"*"<<" ";
//     }
//     // Section II (Stars and Numbers)
//     for(int col=0 ; col<row+1 ; col++){
//         cout<<row+1<<" ";
//         if(col!=row){
//             cout<<"*"<<" ";
//         }
//     }
//     // Section III (Stars)
//     for(int col=0 ; col<(2*rowCount-(row+2)) ; col++){
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }


// OR


// 23. Fancy Pattern #1
    // int rowCount;
    // cout<<"Enter number of rows : ";
    // cin>>rowCount;
    // for(int row=1 ; row<=rowCount ; row++){
    //     // stars
    //     for(int col = 1; col<=2*rowCount-row-1 ; col++){
    //         cout<<"*"<<" ";
    //     }
    //     // numbers and stars
    //     for(int col=1 ; col<=row ; col++){
    //         if(col == row){
    //             cout<<row<<" ";
    //         }
    //         else{
    //             cout<<row<<" "<<"*"<<" ";
    //         }
    //     }
    //     // stars
    //     for(int col = 1; col<=2*rowCount-row-1 ; col++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }














// 24. Solid Half Diamonds
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     // Section I (Upper Half)
//     for(int col=0 ; col<row+1 ; col++){
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }
// for(int row=0 ; row<rowCount ; row++){
//     // Section II (Lower Half)
//     for(int col=0 ; col<rowCount-row+1 ; col++){
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }


// OR
// 24. Solid Half Diamonds
    // int rowCount;
    // cout<<"Enter number of rows : ";
    // cin>>rowCount;
    // for(int row = 1 ; row<=rowCount ; row++){
    //     for(int col = 1 ; col<= row ; col++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int row = 1 ; row<=rowCount ; row++){
    //     for(int col = 1 ; col<= rowCount-row ; col++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
















// // 25. Fancy Pattern #3
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
//     // Section I (Upper Half)
// for(int row=0 ; row<rowCount ; row++){
//     cout<<"*"<<" ";
//     // Forward LOOP
//     for(int col=0 ; col<row ; col++){
//         cout<<col+1<<" ";
//     }
//     // Backward LOOP
//     for(int col=row-1 ; col>0 ; col--){
//         cout<<col<<" ";
//     }
//     if(row!=0){
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }
//     // Section II (Lower Half)
// for(int row=0 ; row<rowCount ; row++){
//     if(row!=rowCount-1){
//         cout<<"*"<<" ";
//     }
//     // Forward Loop
//     for(int col=0 ; col<rowCount-(row+2) ; col++){
//         cout<<col+1<<" ";
//     }
//     // backward Loop
//     for(int col=rowCount-(row+3); col>0 ; col--){
//         cout<<col<<" ";
//     }
//     if(row!=rowCount-1 && row!=rowCount-2){
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }

// OR
// // 25. Fancy Pattern #3
    // int rowCount;
    // cout<<"Enter number of rows : ";
    // cin>>rowCount;

    // for(int row = 1 ; row<= rowCount ; row++){
    //     if(row == 1){
    //         cout<<"*";
    //         cout<<endl;
    //     }
    //     else{
    //         cout<<"*";
    //         for(int col = 1 ; col<row ; col++){
    //             cout<<col;
    //         }
    //         for(int col = row-1 ; col>1 ; col--){
    //             cout<<col-1;
    //         }
    //         cout<<"*";
    //         cout<<endl;
    //     }
    // }
    // for(int row=1 ; row<=rowCount-1 ; row++){
    //     if(row==rowCount-1){
    //         cout<<"*";
    //         cout<<endl;
    //     }
    //     else{
    //         cout<<"*";
    //         for(int col = 1 ; col<=rowCount - row - 1 ; col++){
    //             cout<<col;
    //         }
    //         for(int col = rowCount - row -2 ; col>=1 ; col--){
    //             cout<<col;
    //         }
    //         cout<<"*";
    //         cout<<endl;
    //     }
    // }



















// 26. Fancy Pattern #2
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// // Section I (Upper Half)
// int c=1;
// for(int row=0 ; row<rowCount ; row++){
//     for(int col=0 ; col<row+1 ; col++){
//         cout<<c<<" ";
//         c++;
//         if(col!=row){
//             cout<<"*"<<" ";
//         }
//     }
//     cout<<endl;
// }
// // Section II (Lower Half)
// int start=c-rowCount;
// for(int row=0 ; row<rowCount ; row++){
//     int k = start;
//     for(int col=0 ; col<rowCount-row ; col++){
//         cout<<k<<" ";
//         k++;
//         if(col!=rowCount-row-1){
//             cout<<"*"<<" ";
//         }
//     }
//     start = start - (rowCount - row - 1);
//     cout<<endl;
// }



// int rowCount;
//     cout<<"Enter number of rows dickhead : ";
//     cin>>rowCount;

//     for(int row = 1 ; row<=rowCount ; row++){
//         for(int col=1 ; col<=row ; col++){
//             if(col==row){
//                 cout<<row;
//             }
//             else{
//                 cout<<row<<"*";
//             }
//         }
//         cout<<endl;
//     }

//     for(int row = 1 ; row<=rowCount ; row++){
//         for(int col=1 ; col<= rowCount-row+1; col++){
//             if(col==rowCount-row+1){
//                 cout<<rowCount-row+1;
//             }
//             else{
//                 cout<<rowCount-row+1<<"*";
//             }
//         }
//         cout<<endl;
//     }
















// 27. Floyd's Traingle Pattern
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// int c=1;
// for(int row=0 ; row<rowCount ; row++){
//     for(int col=0 ; col<row+1 ; col++){
//         cout<<c<<" ";
//         c++;
//     }
//     cout<<endl;
// }















// 28. Pascals's Traingle 
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// for(int row=1 ; row<=rowCount ; row++){ // or row<rowCount+1
//     int c=1;
//     for(int col=1 ; col<=row ; col++){ // or col<row+1
//         cout<<c<<" ";
//         c = c * (row-col)/col; // c = c * (i-j)/j
//     }
//     cout<<endl;
// }













// 29. Butterfly Pattern
// int rowCount;
// cout<<"Enter number of rows : ";
// cin>>rowCount;
// // For Upper Half - I
// for(int row=0 ; row<rowCount ; row++){ 
//     // For (i)-stars
//     for(int col=0 ; col<row+1 ; col++){ 
//         cout<<"*"<<" ";
//     }
//     // For (ii)-spaces
//     for(int col=0 ; col<(2*rowCount)-(2*row)-2; col++){ 
//         cout<<" "<<" ";
//     }
//     // For (iii)-stars
//     for(int col=0 ; col<row+1 ; col++){ 
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }
// // For Lower Half - II
// for(int row=0 ; row<rowCount ; row++){ 
//     // For (i)-stars
//     for(int col=0 ; col<rowCount-row ; col++){ 
//         cout<<"*"<<" ";
//     }
//     // For (ii)-spaces
//     for(int col=0 ; col<(2*row); col++){ 
//         cout<<" "<<" ";
//     }
//     // For (iii)-stars
//     for(int col=0 ; col<rowCount-row ; col++){ 
//         cout<<"*"<<" ";
//     }
//     cout<<endl;
// }



























return 0;
}