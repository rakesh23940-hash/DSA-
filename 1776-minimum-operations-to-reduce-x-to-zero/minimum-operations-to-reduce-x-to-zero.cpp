
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

       
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

       
        if (totalSum < x) {
            return -1;
        }

        int target = totalSum - x;

        int i = 0;
        int sum = 0;
        int maxLen = -1;

       
        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while (sum > target) {
                sum -= nums[i];
                i++;
            }

            if (sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        
        if (maxLen == -1) {
            return -1;
        }

      
        return n - maxLen;
    }
};
