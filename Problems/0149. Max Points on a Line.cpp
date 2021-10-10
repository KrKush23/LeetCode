class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)
            return 1;
        
        int res{};
        map<double, int> m;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                double slope{};
                
                if(points[j][0] - points[i][0] == 0){
                    slope = INT_MAX;
                }else{
                    slope =(double)(points[j][1] - points[i][1])/ (double)(points[j][0] - points[i][0]);
                }
                
                res = max(res, ++m[slope]);                
            }
            
            m.clear(); // **** IMPORTANT ****
        }
        
        return res+1;
    }
};
