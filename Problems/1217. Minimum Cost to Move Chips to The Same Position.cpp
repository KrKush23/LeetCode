class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even{0}, odd{0};
        for(auto i:position){
            (i&1) ? odd++ : even++;
        }
        return min(even, odd);
    }
};
