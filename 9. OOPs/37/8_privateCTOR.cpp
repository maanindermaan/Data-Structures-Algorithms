#include<iostream>
using namespace std;

class Box{
    // private:
    int width;

    // ctor
    Box(int _w) : width(_w){}

    public:
    int getWidth() const{
        return width;
    }
    
    void setWidth( int _val){
        width = _val;
    }

    friend class BoxFactory;
};

class BoxFactory{
    int count;

    public:
    Box getABox(int _w){
        ++count;
        return Box(_w);
    }
};

int main(){
    // Box b(5);
    // cout<<b.getWidth();

    // Use case of private Constructor(ctor)
    // Aap chahte ho ki box ka direct object koi bana na paye
    // Lekin box ki ek class hai BoxFactory uske through banao

    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout<<b.getWidth();

    // https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170 
    // This above link have good points about CONSTRUCTOR
return 0;
}