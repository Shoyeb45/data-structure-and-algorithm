class Solution {
public:
    int smallestNumber(int n, int t) {
        int x = n;
        auto prod = [&](int x) -> int {
            int ans = 1;
            while (x) {
                ans *= x % 10;
                x /= 10;
            }
            return ans;
        };
        while (prod(x) % t != 0) {
            x++;
        }
        return x;
    }
};