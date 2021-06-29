class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1]; // SAME AS OVERLAPPING INTERVAL
        });
        
        int cnt{1}; // start from 1
        int arrowPoint{points[0][1]};
        for(int i=1; i<n; i++){
            if(points[i][0] > arrowPoint){
                cnt++;
                arrowPoint = points[i][1];
            }
        }
        return cnt;
    }
};
