
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        int n = fruits.size();
        int i = 0;
        int res = 0;

        for (int j = 0; j < n; j++) {
            f[fruits[j]]++;

            while (f.size() > 2) {
                f[fruits[i]]--;

                if (f[fruits[i]] == 0) {
                    f.erase(fruits[i]);
                }

                i++;
            }

            int len = j - i + 1;
            res = max(res, len);
        }

        return res;
    }
};
