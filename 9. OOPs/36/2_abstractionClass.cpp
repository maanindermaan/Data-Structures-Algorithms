#include<iostream>
#include "bird.h"
using namespace std;

void birdDoesSomething(Bird* &bird){
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat(); 

    // Agar ab mujhe eagle call karna hai or koi interface nahi hai toh mujhe sparrow->eat() ko millions
    // of lines se badalke eagle->eat() karna padta millions of line change karni padti but now
    // Ab sirf mujhe interface mein sparrow ki jagah eagle bhejna hai or khud ba khud change hojega 
} 

int main(){
    // Bird* bird = new sparrow();// sirf bird se hi call kar sakte hai even if it is private
    Bird* bird = new eagle();// Ek line chnage karte hi code ki saari functionality change ho gai

    // sparrow *sp = new sparrow();
    // sp->eat(); ----->>> CANNOT access like this

    birdDoesSomething(bird);



    // Bird * b2 = new Bird(); // cannot be instantiated. Abstract class or interface ka object nahi ban sakta
return 0;
}