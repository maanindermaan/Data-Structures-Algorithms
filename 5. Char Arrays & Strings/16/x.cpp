#include <iostream>
#include<string.h>
using namespace std;

int getLength(char name[]) {
        int length = 0;
        int i = 0; 

        while(name[i] != '\0') {
                length++;
                i++;
        }
        return length;
}

void reverseCharArray(char arr[]){
    int n = strlen(arr);
    int i = 0 ; 
    int j = n-1;

    while(i<=j){
        char a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
        i++;
        j--;
    }
}

void replaceSpaces(char sentence[ ]){
    int n = strlen(sentence);

    for(int i=0; i<n; i++) {
        if(sentence[i] == ' ') {
            sentence[i] = '@';
        }
    }
}

bool checkPalindrome(char arr[]){
    int i=0;
    int j=strlen(arr)-1;
    cout<<i<<"-"<<j<<endl;

    while(i<j){
        cout<<arr[i]<<endl;
        cout<<arr[j]<<endl;
        if(arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void convertIntoUpperCase(char arr[]){
    for(int i=0 ; i<strlen(arr) ; i++){
        arr[i] = toupper(arr[i]);
    }
}



int main() {
//   char name[100];
//   cout<< "Enter your Name " << endl;

//   cin >> name;

//   cout << "Aapka naam: " << name << " hai " << endl;

        // char ch[100];

        // ch[0] = 'a';
        // ch[1] = 'b';
        // cin >> ch[2];

        // cout << ch[0] << ch[1] << ch[2] << endl;

        // char name[100];

        // cin >> name;

        // for(int i=0; i<7; i++) {
        //         cout << "index: " << i << " value: " << name[i] << endl;
        // }

        // int value = (int)name[6];
        // cout << "value is : " << value << endl;


        // char arr[100];
        // //cin >> arr;
        // //getline(cin, arr);
        // cin.getline(arr, 50);

        // cout << arr;
        
        // char name[100];
        // cout<<"Enter the name :-> ";
        // cin >> name;

        // // 1.
        // cout << "length is: " << getLength(name) << endl;
        // cout << "Length is -> " << strlen(name) << endl;

        // // 2.
        // cout << "Initially: " << name << endl;
        // reverseCharArray(name);
        // cout << "After reversal process: " << name << endl;

        // 3.
        // char sentence[100];
        // cin.getline(sentence, 100);

        // replaceSpaces(sentence);
        // cout << "printing sentence " << endl << sentence << endl;

        // 4. 
        // char arr[100] = "naman";
        // cout << "palindrome check: " << checkPalindrome(arr);

        // 5. 
        char arr[100] = "babbar";
        convertIntoUpperCase(arr);
        cout << arr << endl;


  return 0;
}