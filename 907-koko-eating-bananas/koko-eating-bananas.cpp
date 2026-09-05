class Solution {
public:

    int findmax(vector<int>& v) {

        int maxi = INT_MIN;
        int n = v.size();

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }


    long long calculateTotalHours(vector<int>& v, int hourly) {

        long long totalh = 0;
        int n = v.size();

        for(int i = 0; i < n; i++) {
            totalh += (v[i] + hourly - 1) / hourly;
        }

        return totalh;
    }


    long long minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findmax(piles);

        while(low <= high) {

            int mid = low + (high - low) / 2;

            long long totalh = calculateTotalHours(piles, mid);

            if(totalh <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};