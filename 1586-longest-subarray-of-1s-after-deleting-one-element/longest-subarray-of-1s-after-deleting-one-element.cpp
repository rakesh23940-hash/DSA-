class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int zero = 0;
        int ans = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                zero++;
            }
            while(zero>1){
                if(nums[i]==0){
                    zero--;
                }
                i++;
            }
            ans = max(ans,j-i);
        }
        return ans;
        
    }
};