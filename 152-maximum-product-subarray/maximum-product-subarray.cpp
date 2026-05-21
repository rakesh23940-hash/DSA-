class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int minending = arr[0];
        int maxending = arr[0];
        int res = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            int v1 = arr[i];
            int v2 = minending*arr[i];
            int v3 = maxending*arr[i];
            maxending = max(v1, max(v2,v3));
            minending = min(v1, min(v2,v3));
           // res = max({res, maxending, minending});
           res = max(res, maxending);
        }
        return res;
}
 };