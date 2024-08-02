#include <iostream>
using namespace std;

class Nstack
{
public:
    int *a;
    int *top;
    int *next;
    int n;        // no. of stcaks
    int size;     // size of main array
    int freespot; // tells free space in main array

    // Constructor
    Nstack(int n , int size){
        this->n = n;
        this->size = size;
        freespot = 0;

        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i=0 ; i<size ; i++){
            if(i == size-1){
                next[i] = -1;
                break;
            }
            next[i] = i+1;
        }

        for(int i=0 ; i<n ; i++){
            top[i] = -1;
        }
    }

    // Destructor
    ~Nstack(){
        delete []a;
        delete []top;
        delete []next;
    }


    // Push X into mth stack
    bool push(int X, int m){
        if(freespot == -1){
            cout<<"STACK OVERFLOW";
            return false;
        }

        int index = freespot;
        freespot = next[index];
        a[index] = X;
        next[index] = top[m-1];
        top[m-1] = index;

        cout<<X<<endl;

        return true;
    }

    // pop from mth stack
    int pop(int m){
        if(top[m-1] == -1){
            cout<<"Stack Underflow";
            return false;
        }
        
        int index = top[m-1];
        top[m-1] = next[index];
        int poppedElement = a[index];
        next[index] = freespot;
        freespot = index;

        return poppedElement;
    }

    
};

int main()
{
    Nstack s(3,6);
    cout<<s.push(10,1)<<endl;
    cout<<s.push(20,2)<<endl;
    cout<<s.pop(10)<<endl;
    return 0;
}