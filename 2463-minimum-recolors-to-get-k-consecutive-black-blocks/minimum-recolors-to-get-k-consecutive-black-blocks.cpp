class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int count =0;
        int ans = INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                count++;
            }

        }
        ans = count;
        for(int i=k;i<n;i++){
            if(blocks[i-k]=='W'){
                count--;
            }
            if(blocks[i]=='W'){
                count++;
            }
            ans = min(ans,count);
        }
        return ans;
        
    }
};