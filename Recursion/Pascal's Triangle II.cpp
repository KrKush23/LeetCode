class Solution {
public:
    // row index starts from 0
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> p{};
        for(int i=0;i<=rowIndex;i++){
            p.push_back(vector<int> (i+1));
            for(int j=0;j<=i;j++){
                if(j==0||j==i)
                    p[i][j]=1;
                else
                    p[i][j]=p[i-1][j-1]+p[i-1][j];
            }
        }
        return p[rowIndex];
    }
};
