class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n; i++) {

            int dist = abs(arr[i] - x);

            pair<int,int> curr{dist, arr[i]};

            if(pq.size() < k) {
                pq.push(curr);
            }
            else if(curr < pq.top()) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(res.begin(), res.end());

        return res;
    }
};