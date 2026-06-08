class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> left;
        vector<int> equal;
        vector<int> right;

        for(int num : nums){

            if(num < pivot)
                left.push_back(num);

            else if(num > pivot)
                right.push_back(num);

            else
                equal.push_back(num);
        }

        vector<int> ans;

       for(int i = 0; i < left.size(); i++)
        ans.push_back(left[i]);

       for(int k = 0; k < equal.size(); k++)
        ans.push_back(equal[k]);

       for(int j = 0; j < right.size(); j++)
        ans.push_back(right[j]);

        return ans;
    }
};