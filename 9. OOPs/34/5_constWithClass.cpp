#include<iostream>
using namespace std;

class abc{
    // mutable int x;
    int x;
    int *y;
    int z;

    public:
    abc(){
        x = 0;
        y = new int(0);
    }

    abc(int x, int y , int z = 0) { // z is deafult argument here
        this->x = x;
        this->y = new int(y);
        z = z;
    }

    int getX()const {

        // x = 50; // cannot be changed due to const declare above only change when mutable
        return x;
    }
    void setX(int val){
        x = val;
    }

    int getY() const{
        int f = 100;
        // y = &f; // error cannot be change the pointer due to const above
        return *y;
    }
    void setY(int val){
        *y = val;
    }

    // int getZ(){
    //     z=10; // no error becuase it is not a constant function 
    //     return z;
    // }


    int getZ()const{
        return z;
    }

    void printABC(const abc &a){
        // a.setX(); // error because setX is not const function
        cout<<a.getX()<<endl;
        cout<<a.getY()<<endl;
        // cout<<a.getZ()<<endl;  // will not work because int getZ() is not a constant function
        cout<<a.getZ()<<endl;
    }
};

int main(){
    // abc a(1,2);
    // a.printABC(a);
    abc a(1,2,3); // z will override and convert 0 to 3 and update while returning
    a.printABC(a);
return 0;
}