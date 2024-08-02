#include <iostream>
using namespace std;

void print(int n){
	// base case
	if(n==0){
		return; 
	}

	cout<< n <<" ->";

	print(n-1);
}

void printCounting(int n) {
	//base case
	if(n == 0) {
		return;
	}

	//processing
	cout << n << " ";
	

	//re4ciursive relation
	printCounting(n-1);	
}

int main() {

	int n;
	cout << "Enter the value of n  " << endl;
	cin >> n;

	print(n);
	cout << endl;

	return 0;
}