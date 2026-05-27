class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left<=right){
             int guess = (left+right)/2;
            if(nums[guess]==target){
            return guess;
            }
            else if(target> nums[guess]){
            left = guess+1;
            }
            else {
                right = guess-1;
            }

    }
        return -1; 
    }
};