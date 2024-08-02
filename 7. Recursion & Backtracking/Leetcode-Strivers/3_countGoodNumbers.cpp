#include <iostream>
using namespace std;
int main()
{

    return 0;
}

// method-1
class Solution
{
public:
    const int MOD = 1000000007;

    long long recursive(long long n, int index, long long ans)
    {
        // base case
        if (index == n)
        {
            return ans % MOD;
        }

        // Solve one case
        if (index % 2 == 0)
        {
            ans = (ans * 5) % MOD;
        }
        else
        {
            ans = (ans * 4) % MOD;
        }

        return recursive(n, index + 1, ans);
    }

    int countGoodNumbers(long long n)
    {
        long long ans = recursive(n, 0, 1);
        return static_cast<int>(ans);
    }
};

// method-2
class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long N, long long R) {
        if (R == 0) {
            return 1;
        }

        if (R == 1) {
            return N % MOD;
        }

        long long ans = 1;
        long long know = power(N, R / 2) % MOD;

        if (R % 2) {
            ans = (ans * N) % MOD;
        }

        return (ans * ((know * know) % MOD)) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long ans = power(20, n / 2);

        if (n % 2) {
            ans = (ans * 5) % MOD;
        }

        return static_cast<int>(ans);
    }
};


// method-3
// best solution
class Solution {
public:
    const int MOD = 1000000007;

    long long recursivePow(long long base, long long exp) {
        // base case
        if (exp == 0) {
            return 1;
        }

        long long half = recursivePow(base, exp / 2);
        half = (half * half) % MOD;

        if (exp % 2 != 0) {
            half = (half * base) % MOD;
        }

        return half;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Number of even indices
        long long oddCount = n / 2;         // Number of odd indices

        long long evenResult = recursivePow(5, evenCount);
        long long oddResult = recursivePow(4, oddCount);
        long long result = (evenResult * oddResult) % MOD;

        return static_cast<int>(result);
    }
};
