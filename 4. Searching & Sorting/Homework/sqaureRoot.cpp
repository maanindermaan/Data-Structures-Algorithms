#include <iostream>
using namespace std;

double squareRoot(double num, double precision) {
    if (num < 0){
        return -1; // Invalid input, square root of negative number is undefined
    }

    double start = 0.0;
    double end = num;
    double mid = 0.0;

    while (end - start > precision) {
        mid = start + (end - start) / 2;
        double square = mid * mid;

        if (square == num)
            return mid; // Exact square root found

        if (square < num)
            start = mid; // Adjust lower boundary

        else
            end = mid; // Adjust higher boundary
    }

    return start + (end - start) / 2; // Approximate square root
}

int main() {
    double num = 100.0;
    double precision = 0.00001;

    double result = squareRoot(num, precision);

    cout << "Square root of " << num << " is approximately " << result << endl;

    return 0;
}
