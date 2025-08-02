class Solution {
public:
    const long long mod = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long good_even = power(5, even_positions);
        long long good_odd = power(4, odd_positions);

        return (good_even * good_odd) % mod;
    }
};
