class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor)
            callbfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    void callbfs(vector<vector<int>>& image, int i, int j,int oldColor, int newColor){
        if(i<0 || j<0 || i >= image.size() || j>= image[i].size() || image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        callbfs(image, i+1, j  , oldColor, newColor); //down
        callbfs(image, i  , j+1, oldColor, newColor); //right
        callbfs(image, i-1, j  , oldColor, newColor); //up
        callbfs(image, i  , j-1, oldColor, newColor); //left
    }
};
