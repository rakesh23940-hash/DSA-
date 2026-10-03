class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

          
            if (nums[i] % 2 == 1)
                prefixSum++;

            int required = prefixSum - k;

            if (mp.find(required) != mp.end())
                count += mp[required];

            mp[prefixSum]++;
        }

        return count;
    }
};