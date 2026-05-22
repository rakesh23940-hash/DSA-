class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int bestending = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = max(v1, v2);
            ans = max(ans, bestending);
        }

        return ans;
    }

    int minSubArray(vector<int>& nums) {
        int n = nums.size();

        int bestending = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = min(v1, v2);
            ans = min(ans, bestending);
        }

        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum = totalSum + nums[i];
        }

        int maxSum = maxSubArray(nums);
        int minSum = minSubArray(nums);

        if (maxSum < 0) {
            return maxSum;
        }

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};