class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int spot1 = values[0] + 0;
        int res{};
        
        for(int i=1; i<values.size(); i++){
            res = max(res, spot1 + values[i] - i);
            spot1 = max(spot1, values[i] + i);
        }
        
        return res;
    }
};
