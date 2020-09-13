class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{};
        int low{intervals[0][0]}, high{intervals[0][1]};
        
        for(int i=1; i<intervals.size(); i++){
            //No OVERLAPPING
            if(intervals[i][0] > high){ 
                res.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1]
            }//OVERLAPPING   
            else{
                high = max(high, intervals[i][1]);   
            }
        }
        
        res.push_back({low, high});
        return res;
    }
};
