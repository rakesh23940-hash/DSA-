class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(maxSum,currSum);
        }

        return maxSum;
    }

     int minSubArray(vector<int>& nums) {
        int n = nums.size();

        int currSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < n; i++) {
            currSum = min(nums[i],currSum+nums[i]);
            minSum = min(minSum,currSum);
        }

        return minSum;
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