class Solution {
        int n, m;
        int oldColor;
        vector<int> dx{0, -1, 0, 1};
        vector<int> dy{-1, 0, 1, 0};
public:
    bool isValid(vector<vector<int>>& image, int i, int j){
        if(i<0 or j<0 or i>=n or j>=m or image[i][j] != oldColor)
            return 0;
        return 1;        
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int newColor){
        image[i][j] = newColor;
        for(int k=0; k<4; k++){
            if(isValid(image, i+dx[k], j+dy[k]))
                dfs(image, i+dx[k], j+dy[k], newColor);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        
        oldColor = image[sr][sc];
        if(image[sr][sc] != newColor)
            dfs(image, sr, sc, newColor);
        return image;
    }
};
