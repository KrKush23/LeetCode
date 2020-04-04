class Solution {
public:
    int islandPerimeter(vector<vector<int>>& a) {
        if(a.empty())    return 0 ;
        int m=a.size(), n = a[0].size(), ans{};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    ans+=4;
                    if(i>0 and a[i-1][j]==1)    ans-=2;
                    if(j>0 and a[i][j-1]==1)    ans-=2;
                }
            }
        }
        return ans;
    }
};
