class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p{};
        for(int i=0;i<numRows;i++){
            p.push_back(vector<int> (i+1));
            for(int j=0;j<=i;j++){
                if(j==0||j==i)
                    p[i][j]=1;
                else
                    p[i][j]=p[i-1][j-1]+p[i-1][j];
            }
        }
        return p;
    }
};
