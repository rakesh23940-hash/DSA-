class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int count = 0;
        int N = flowerbed.size();

        for(int i = 0; i < N; i++) {

            if(flowerbed[i] == 0 &&
               (i == 0 || flowerbed[i - 1] == 0) &&
               (i == N - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                count++;
            }
        }

        if(count >= n)
            return true;

        return false;
    }
};