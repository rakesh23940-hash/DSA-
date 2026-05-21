class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int bestEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(nums[i], bestEnding + nums[i]);
            ans = max(ans, bestEnding);
        }

        return ans;
    }

    int minSubarray(vector<int>& nums) {
        int bestEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(nums[i], bestEnding + nums[i]);
            ans = min(ans, bestEnding);
        }

        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int mx = maxSubarray(nums);
        int mn = minSubarray(nums);

        return max(abs(mx), abs(mn));
    }
};