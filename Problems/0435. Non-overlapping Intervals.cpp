class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1]; // sort a/c to END TIME
        });
        
        int cnt{0};
        int last = intervals[0][1]; // keep track of last end time
        for(int i=1; i<n; i++){
            if(intervals[i][0] < last)
                cnt++;
            else
                last = intervals[i][1];
        }
        return cnt;
    }
};
