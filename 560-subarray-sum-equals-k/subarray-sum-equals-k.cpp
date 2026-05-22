class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int sum = 0;
        int res = 0;
        int n = nums.size();
        f[0]= 1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int find = (sum-k);
            int freq = f[find];
            res+=freq;
            f[sum]++; 
        }
        return res;
    }
};