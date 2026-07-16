using ll = long long;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref_gcd(n);

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            pref_gcd[i] = __gcd(mx, nums[i]);
        }        

        sort(pref_gcd.begin(), pref_gcd.end());
        ll ans = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            ans += __gcd(pref_gcd[l], pref_gcd[r]);
        }

        return ans;
    }
};