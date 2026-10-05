class Solution {
public:

    int findMax(vector<int>& weights) {
        int maxi = INT_MIN;

        for(int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }

        return maxi;
    }

    int calculateDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentWeight = 0;

        for(int i = 0; i < weights.size(); i++) {

            if(currentWeight + weights[i] <= capacity) {
                currentWeight += weights[i];
            }
            else {
                days++;
                currentWeight = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = findMax(weights);

        int high = 0;
        for(int i=0;i<weights.size();i++) {
            high += weights[i];
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int daysNeeded = calculateDays(weights, mid);

            if(daysNeeded <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};