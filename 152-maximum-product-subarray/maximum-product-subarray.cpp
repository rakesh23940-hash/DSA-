class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1;
        int suffx = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n;i++){
            if(pref==0){
                pref=1;
            }
            if(suffx==0){
                suffx=1;
            }
            pref = pref*nums[i];
            suffx = suffx*nums[n-i-1];
            ans = max(ans,max(pref,suffx));
        }
        return ans;
        
    }
};