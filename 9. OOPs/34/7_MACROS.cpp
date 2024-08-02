#include<iostream>
using namespace std;

#define PI 3.14159465
#define MAXX(x,y) {x>y ? x : y}

// float circleArea(float r){
//     return 3.14 * r * r;
// }

float circleArea(float r){
    return PI * r * r;
}


float perimeter(float r){
    return 2* PI * r;
}

void fun(){
    int a = 10;
    int b = 11;

    int c = MAXX(a, b);
}

int main(){
    cout<<perimeter(65.4);
return 0;
}