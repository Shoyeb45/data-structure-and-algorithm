class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        auto sum_n = [](int n, int a) -> int {
            return (n * (2 * a + (n - 1) * 2)) / 2;
        };

        int sum_odd = sum_n(n, 1);
        int sum_even = sum_n(n, 2);
        return __gcd(sum_odd, sum_even);
    }
};