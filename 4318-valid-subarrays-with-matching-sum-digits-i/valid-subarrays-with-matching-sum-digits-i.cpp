class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                int lastDigit = sum % 10;

                long long firstDigit = sum;
                while (firstDigit >= 10) {
                    firstDigit /= 10;
                }

                if (firstDigit == x && lastDigit == x) {
                    count++;
                }
            }
        }

        return count;
    }
};