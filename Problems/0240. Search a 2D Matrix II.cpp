class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // start from TOP RIGHT
        int i=0, j=m-1;
        while(i<n and j>=0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target) // go DOWN if smaller than TARGET
                i++;
            else                           // go LEFT if larger than TARGET
                j--;
        }
        return false;
    }
};
