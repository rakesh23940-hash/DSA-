class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> f;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        for(auto it : f) {
            if(it.second > n / 2) {
                return it.first;
            }
        }

        return -1;
    }
};