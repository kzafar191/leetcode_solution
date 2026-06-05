// Last updated: 5/6/2026, 5:10:58 pm
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long result = 0;

        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};