#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Car{
    public:
    int pos , speed;
    Car(int pos , int speed){
        this->pos = pos; 
        this->speed = speed;
    }
    static bool myComp(Car &a , Car &b){
        return a.pos<b.pos;
    }
};

int carFleet(vector<int> &pos , vector<int>& speed , int target){
    vector<int>cars;
    for(int i=0 ; i<pos.size() ; i++){
        Car car(pos[i] , speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin() , cars.end() , Car::myComp);

    stack<float>st;

    for(int i=0 ; i<cars.size() ; i++){
        float time = (target - pos[i])/((float)speed[i]);
        while(!st.empty() && time >= st.top()){
            st.pop();
        }
        st.push(time);
    }
    return st.size();
}

int main(){
    vector<int> pos {10,8,0,5,3};
    vector<int> speed {2,4,1,1,3};

    int target = 12;

    return carFleet(pos , speed , target);
return 0;
}






// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;

// class Car {
// public:
//     int pos, speed;
//     Car(int pos, int speed) {
//         this->pos = pos;
//         this->speed = speed;
//     }

//     // Define the comparison function as a static member function
//     static bool myComp(Car& a, Car& b) {
//         return a.pos < b.pos;
//     }
// };

// size_t carFleet(vector<int>& pos, vector<int>& speed, int target) {
//     vector<Car> cars; // Store Car objects instead of integers

//     for (int i = 0; i < pos.size(); i++) {
//         Car car(pos[i], speed[i]);
//         cars.push_back(car);
//     }

//     sort(cars.begin(), cars.end(), Car::myComp); // Use the static member function for sorting

//     stack<float> st;

//     for (int i = 0; i < cars.size(); i++) {
//         float time = (target - cars[i].pos) / static_cast<float>(cars[i].speed);
//         while (!st.empty() && time >= st.top()) {
//             st.pop();
//         }
//         st.push(time);
//     }
//     return st.size();
// }

// int main() {
//     vector<int> pos{ 10, 8, 0, 5, 3 };
//     vector<int> speed{ 2, 4, 1, 1, 3 };

//     int target = 12;

//     cout << "Number of car fleets: " << carFleet(pos, speed, target) << endl;
//     return 0;
// }










// /MY KINDA APPROACH -> Only Push Bigger element in stack (stack neccesaary to compare the top element you can use any ds.)
// 1. Some errors as i didn't remeber we have different position and posiitons array was not sorted
// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         vector<float>time(position.size());
//         stack<float>st;
//         int ans = 0;

//         for(int i=0 ; i<position.size(); i++){
//             time[i] = float(target - position[i])/float(speed[i]);
//         }

//         int i=position.size()-1;

//         for(auto i : time){
//             cout<<i<<" ";
//         }
//         cout<<endl;

//         while(i>=0){
//             if(st.empty()){
//                 st.push(time[i]);
//                 i--;
//             }
//             else{
//                 if(!st.empty() && st.top() >= time[i]){
//                     i--;
//                 }
//                 else{
//                     st.pop();
//                     ans++;
//                     st.push(time[i]);
//                     i--;
//                 }
//             }
//         }
//         return ans+1;
//     }
// };





// 2. Coorect Approach
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float>> cars(n); // Pair to store position and time

        for (int i = 0; i < n; ++i) {
            float time = float(target - position[i]) / float(speed[i]);
            cars[i] = {position[i], time};
        }

        // Sort cars based on their starting positions
        sort(cars.begin(), cars.end());

        stack<float> st; // Stack to maintain the fleets

        for (int i = n - 1; i >= 0; --i) {
            float current_time = cars[i].second;
            if (st.empty() || st.top() < current_time) {
                st.push(current_time);
            }
        }

        return st.size();
    }
};
