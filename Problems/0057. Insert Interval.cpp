#define pb push_back
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{};
        for(auto i:intervals){
            // newInterval is after the current interval
            if(i[1] < newInterval[0])
                res.pb(i);
            // newInterval is before the current interval
            else if(i[0] > newInterval[1]){
                res.pb(newInterval);
                newInterval = i;
            }
            // overlapping of intervals
            else{
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }
        }
        res.pb(newInterval);
        return res;        
    }
};
