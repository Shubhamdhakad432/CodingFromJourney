class Solution {
public:
	int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		long a = labs(dividend), b = labs(divisor), ans = 0;
        long sign = dividend<0 ^ divisor<0? -1 : 1;
		while (a >= b) {
			long temp = b, m = 1;
			while (temp << 1 <= a) {
				temp <<= 1;
				m <<= 1;
			}
			a -= temp;
			ans += m;
		}
		return sign *ans;
	}
};