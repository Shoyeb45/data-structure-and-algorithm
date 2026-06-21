class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        sort(c.begin(), c.end());

        int ans = 0;

        for (auto& x: c) {
            if (coins > 0 && coins - x >= 0) {
                ans++;
                coins -= x;
            }
        }
        return ans;
    }
};