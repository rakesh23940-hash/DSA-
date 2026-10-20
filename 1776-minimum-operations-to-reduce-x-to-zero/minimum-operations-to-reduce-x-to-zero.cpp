class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = 0;
        for(int num:nums){
            totalsum+=num;
        }
        if(totalsum<x){
            return -1;
        }
        int target = totalsum-x;
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxlen = -1;
        for(j=0;j<n;j++){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
                maxlen = max(maxlen,j-i+1);
            }

        }
        if(maxlen==-1){
            return -1;
        }
        return n-maxlen;
        
    }
};