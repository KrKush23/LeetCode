class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty())
            return 0;
        int total{};
        for (int i = 1; i < timeSeries.size(); i++) {
            total += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return total + duration;
    }
};
