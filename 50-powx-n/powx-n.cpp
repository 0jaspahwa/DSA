class Solution {
public:
    double myPow(double x, int n) {
        // Base Case: Anything to the power of 0 is 1.
        if (n == 0) {
            return 1.0;
        }

        // Handle negative exponents.
        // We convert n to a long to avoid integer overflow if n is INT_MIN.
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        return powerHelper(x, power);
    }

private:
    double powerHelper(double x, long long n) {
        // This is the recursive base case.
        if (n == 0) {
            return 1.0;
        }

        // Recursively calculate the power of n/2.
        // This is the "divide and conquer" part of the algorithm.
        double half = powerHelper(x, n / 2);

        // Square the result of the half-power.
        double res = half * half;

        // **THE FIX:** If n is odd, we need to multiply by an extra x.
        // We check if the exponent 'n' is odd, not the base 'x'.
        if (n % 2 == 1) {
            res = res * x;
        }

        return res;
    }
};
