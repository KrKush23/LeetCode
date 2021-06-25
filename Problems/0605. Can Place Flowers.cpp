class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt{0}, l = flowerbed.size();
        int i{0};
        while (i < l) {
            if (flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) 
                and (i == l - 1 or flowerbed[i + 1] == 0)) {
                flowerbed[i++] = 1; // 'i' increases cz adjacent to it..we can't place flower
                cnt++;
            }
            if (cnt >= n)
                return 1;
            i++; // each time
        }
        return 0;
    }
};
