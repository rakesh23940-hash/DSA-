class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int sum = 0;
        int count = 0;
        int n = nums.size();
        f[0]= 1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            count+=f[sum-k];
            f[sum]++; 
        }
        return count;
    }
};