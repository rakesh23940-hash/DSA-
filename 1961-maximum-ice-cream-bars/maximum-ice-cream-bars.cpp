class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int n = costs.size();
        long long candies = 0;
        vector<int> candy;
        for(int i = 0 ; i < n ; i++)
        {
            candies += costs[i];
            if(candies <= coins)
            {
                candy.push_back(costs[i]);
            }
        } 
        return candy.size();
    }
};