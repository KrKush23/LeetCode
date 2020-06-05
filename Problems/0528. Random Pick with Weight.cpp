class Solution {
    vector<int> presum{};
    int total{};
public:
    Solution(vector<int>& w) {
        total = 0;
        for(auto i:w){
            total += i;
            presum.emplace_back(total);
        }
    }
    int pickIndex() {
        int target = rand()%total;
        return upper_bound(presum.begin(), presum.end(), target) - presum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
