class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int no_del = arr[0];
        int one_del = INT_MIN;
        int res = arr[0];

        for (int i = 1; i < n; i++) {
            int prev_no_del = no_del;

            no_del = max(arr[i], no_del + arr[i]);

            if (one_del == INT_MIN)
                one_del = prev_no_del;
            else
                one_del = max(prev_no_del, one_del + arr[i]);

            res = max(res, max(no_del, one_del));
        }

        return res;
    }
};