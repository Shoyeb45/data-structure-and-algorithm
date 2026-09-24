class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto digit_sum = [&](int num) -> int {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        for (int i = 0; i < nums.size(); i++) {
            if (digit_sum(nums[i]) == i) return i;
        }
        return -1;
    }
};