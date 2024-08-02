#include<iostream>
using namespace std;
int main(){

return 0;
}
bool isAnagram(char a[], char b[]){
    char arr[256] = {0};
    
    int size1 = strlen(a); // Use strlen to get the length of C-style strings
    int size2 = strlen(b);
    
    if(size1 != size2){
        return false;
    }
    
    for(int i=0 ; i<size1 ; i++){
        arr[a[i]]++;
        arr[b[i]]--;
    }
    
    for(int i = 0 ; i<256 ; i++){
        if(arr[i] != 0){ // Check the value (count) associated with each character
            return false;
        }
    }
       
    return true;
}