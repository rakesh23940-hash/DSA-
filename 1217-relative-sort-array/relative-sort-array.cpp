class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> freq;

     
        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;


        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        vector<int> rem;

        for (auto it : freq) {
            while (it.second > 0) {
                rem.push_back(it.first);
                it.second--;
            }
        }


        sort(rem.begin(), rem.end());


        for (int x : rem) {
            ans.push_back(x);
        }

        return ans;
    }
};