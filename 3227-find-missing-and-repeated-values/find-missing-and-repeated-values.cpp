class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        long long n = grid.size();
        long long N = n * n;

        long long SN = (N * (N + 1)) / 2;
        long long S2N = (N * (N + 1) * (2 * N + 1)) / 6;

        long long s = 0;
        long long s2 = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s += grid[i][j];
                s2 += (long long)grid[i][j] * grid[i][j];
            }
        }

        // x = repeated
        // y = missing

        long long val1 = s - SN;       // x - y
        long long val2 = s2 - S2N;     // x² - y²

        val2 = val2 / val1;            // x + y

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};