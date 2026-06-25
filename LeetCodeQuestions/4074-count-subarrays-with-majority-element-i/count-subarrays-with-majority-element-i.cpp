class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0] == target;

        for (int i = 1; i < nums.size(); i++) {
            pref[i] += pref[i - 1] + (nums[i] == target);
        }

        auto count = [&](int i, int j) -> int {
            return pref[j] - (i - 1 >= 0 ? pref[i - 1] : 0);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // cout << i << " , " << j << " -> count ";
                int cnt = count(i, j);
                // cout << cnt << "\n";
                int len = j - i + 1;
                if (cnt > len / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};