#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // creation 
    unordered_map<string , int> m; // {key , value}

    // insertion
    // 1. Pair
    pair<string , int> p = make_pair("Scorpio" , 9);
    m.insert(p);

    // 2. Pair
    pair<string , int> p2("Alto" , 3);
    m.insert(p2);

    // 3. Simple array method
    m["Fortuner"] = 10;

    // Acces
    // 1.
    cout<<m.at("Alto")<<endl;
    // cout<<m.at("alto")<<endl; -> error
    cout<<m.at("Scorpio")<<endl;

    // 2.
    cout<<m["Fortuner"]<<endl;


    // Search
    // 1. Using count
    cout<<m.count("Scorpio")<<endl;
    cout<<m.count("Legender")<<endl;

    // 2.
    if(m.find("Fortuner") != m.end()){
        cout<<"Fortuner Found"<<endl;
    }
    else{
        cout<<"Fortuner Not Found"<<endl;
    }

    // Size
    cout<<m.size()<<endl;
    cout<<m["Hummer"]<<endl; // -> entry creater and zero value inserted
    cout<<m.size()<<endl;

    // Printing
    for(auto i : m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

return 0;
}