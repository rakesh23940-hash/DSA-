class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = prefix[i + 1];
        }

        return nums;
    }
};