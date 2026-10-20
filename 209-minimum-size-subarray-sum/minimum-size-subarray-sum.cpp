class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int res = INT_MAX;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>=target){
                int len = j-i+1;
                res = min(res,len);
                sum-=nums[i];
                i++;
            }
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
        
    }
};