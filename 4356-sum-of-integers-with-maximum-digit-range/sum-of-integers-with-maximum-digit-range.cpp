class Solution {
public:
    vector<int> NumToArr(int n) {
        vector<int> ans;

        if (n == 0) {
            ans.push_back(0);
            return ans;
        }

        while (n > 0) {
            int last_digit = n % 10;
            ans.push_back(last_digit);
            n /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        vector<int> ranges;

        for (int i = 0; i < n; i++) {

            vector<int> digits = NumToArr(nums[i]);

            int large = *max_element(digits.begin(), digits.end());
            int small = *min_element(digits.begin(), digits.end());

            ranges.push_back(large - small);
        }

        int maxRange = *max_element(ranges.begin(), ranges.end());

        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (ranges[i] == maxRange) {
                sum += nums[i];
            }
        }

        return sum;
    }
};