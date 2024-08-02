#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> cars)
{
    vector<double> answer(cars.size(), -1); // collision time of ith car with next car
    stack<int> st;
    for (int i = cars.size() - 1; i >= 0; i--)
    {
        // check if car ahead of current car is faster or not
        while (!st.empty() && cars[st.top()][1] >= cars[i][1])
        { // cars[0] -> position and cas[1] -> speed
            st.pop();
        }

        while (!st.empty())
        {
            // collision hota hai ya nahi
            // Stack ke top pe jo hai uska collision time.
            double collisionTime = (double)(cars[st.top()][0] - cars[i][0]) / (double)(cars[i][1] - cars[st.top()][1]); // col time = delta pos / delta speed
            // less than equal to hoga tabhi collision hoga
            if (answer[st.top()] == -1 || collisionTime <= answer[st.top()])
            {
                answer[i] = collisionTime;
                break;
            }
            // agar asa na ho to pop kardo or fir next ko dekhlo
            st.pop();
        }
        st.push(i);
    }
    return answer;
}

int main()
{
    vector<vector<int>> cars{
        {3, 4},
        {5, 4},
        {6, 3},
        {9, 1}};

    vector<double> ans = getCollisionTimes(cars);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
