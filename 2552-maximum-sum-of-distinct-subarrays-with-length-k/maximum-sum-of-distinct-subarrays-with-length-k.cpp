
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int left = 0;
        long long sum = 0;
        long long maxi = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            sum += nums[right];
            mp[nums[right]]++;

            // Window size should not exceed k
            if (right - left + 1 > k) {
                sum -= nums[left];
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            // Check size k and all elements distinct
            if (right - left + 1 == k && mp.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
