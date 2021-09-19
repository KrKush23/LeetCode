class Solution {
    long mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long res{};
        int maxH{}, maxW{};
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        maxH = horizontalCuts[0];
        for(int i=1; i<horizontalCuts.size(); i++)
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        maxH = max(maxH, h - horizontalCuts.back());
        
        maxW = max(maxW, verticalCuts[0]);
        for(int i=1; i<verticalCuts.size(); i++)
           maxW = max(maxW, verticalCuts[i] - verticalCuts[i-1]);
        maxW = max(maxW, w - verticalCuts.back());
        
        res = maxH * (long)maxW;
        res %= mod;
        
        return res;
    }
};
