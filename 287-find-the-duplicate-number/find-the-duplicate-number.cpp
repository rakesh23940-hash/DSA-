class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> temp;

        for(int i = 0; i < nums.size(); i++) {

            if(temp.find(nums[i]) != temp.end()) {
                return nums[i];
            }

            temp.insert(nums[i]);
        }

        return -1;
    }
};