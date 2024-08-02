// HEADER FILE
#if !defined(BIRD_H) // jab bhi aap agar bird.h ko baar baar bhi include karoge tab bhi yeah 1 baar hi include hoga
#define BIRD_H
#include<iostream>

// INTERFACE
class Bird{ // due to pure virtual function this class -> has become -> interface  
    public:
    virtual void eat() = 0; // pure virtual function 
    virtual void fly() = 0; // one more interface
    // Ye jo bird hai iska khudse koi vajud ni hai kyunki bird boht type ki hoti hai spaarow is a bird , piegon is a bird. To humne bola yeah bird hai yeah ek interface hai, baaki birds ki jo classes hongi jaise ki sparrow hai eagle hai vo isko implement krengi i.e. isko inherit krengi or jab bhi koi class inherit kregi unko yeah 2 function fly and eat zrur se zrur implement krne padenge tab hi yeah bird khelayegi nahi toh nahi kehlayegi
    //classes that inherits this class have to implement pure virtual function 
};


// IMPLEMENTATIONS
class sparrow : public Bird{
    private:
    void eat(){
        std::cout<<"Sparrow is eating\n";
    }
    void fly(){
        std::cout<<"Sparrow is flying\n";
    }
};

class eagle : public Bird{
    private:
    void eat(){
        std::cout<<"Eagle is eating\n";
    }
    void fly(){
        std::cout<<"Eagle is flying\n";
    }
};
//  KOI baad mein naya bird aaye toh usko bhi add krdo simple


#endif // BIRD_H
