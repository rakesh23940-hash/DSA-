class Solution {
public:

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

        vector<vector<int>> res;

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        int n = intervals.size();

        for (int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2) {
                end1 = max(end1, end2);
            }
            else {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        res.push_back({start1, end1});

        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        bool insert = false;

        int n = intervals.size();

        for (int i = 0; i < n; i++) {

            if (insert ==false && newInterval[0] < intervals[i][0]) {
                ans.push_back(newInterval);
                insert = true;
            }

            ans.push_back(intervals[i]);
        }

        if (insert==false) {
            ans.push_back(newInterval);
        }

        return mergeIntervals(ans);
    }
};