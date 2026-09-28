class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool negative = (dividend < 0) != (divisor < 0);

        long long dividendAbs = dividend;
        long long divisorAbs = divisor;

        if (dividendAbs < 0) {
            dividendAbs = -dividendAbs;
        }

        if (divisorAbs < 0) {
            divisorAbs = -divisorAbs;
        }

        long long quotient = 0;

        while (dividendAbs >= divisorAbs) {

            long long current = divisorAbs;
            long long multiple = 1;

            while ((current << 1) <= dividendAbs) {

                current <<= 1;
                multiple <<= 1;
            }

            dividendAbs -= current;
            quotient += multiple;
        }

        if (negative) {
            quotient = -quotient;
        }

        return static_cast<int>(quotient);
    }
};