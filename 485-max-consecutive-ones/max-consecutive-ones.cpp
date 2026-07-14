class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int mx = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
               mx= max(mx,curr);
            }
            else{
                curr=0;
            }
        }
        return mx;
        
    }
};