class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] > maxVal)
                maxVal = nums[i];

            if(nums[i] < minVal)
                minVal = nums[i];
        }

        long long diff = maxVal - minVal;

        return diff * k;
    }
};