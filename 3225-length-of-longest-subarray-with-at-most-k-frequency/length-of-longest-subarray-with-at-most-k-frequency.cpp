class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        int low = 0;
        int res = 0;

        for(int high = 0; high < nums.size(); high++) {

            freq[nums[high]]++;

            while(freq[nums[high]] > k) {
                freq[nums[low]]--;
                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};