#include <iostream>
using namespace std;

int factorial(int n) {

	//base case
	if(n == 1)
		return 1;

	int chotiProblemAns = factorial(n-1);
	int badiProblemAns = n * chotiProblemAns;

	return badiProblemAns;
}

int fact(int n){
	if(n==1){
		return 1;
	}
	int ans = n*fact(n-1);
	return ans;
}

int main() {

	int n;
	cout << "Enter the value of n  " << endl;
	cin >> n;

	int ans  = fact(n);

	cout << "Answer is: " << ans << endl;

	return 0;
}