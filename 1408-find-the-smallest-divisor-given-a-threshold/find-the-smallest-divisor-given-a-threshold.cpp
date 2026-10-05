class Solution {
public:
    int findMax(vector<int>&nums){
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int calculateSum(vector<int>&nums,int divisor){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = findMax(nums);
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum = calculateSum(nums,mid);
            if(sum<=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};