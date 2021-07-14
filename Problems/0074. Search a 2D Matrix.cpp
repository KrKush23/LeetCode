class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // low and high values of index
        // if nos. are in a 1D array
        int low = 0, high = n*m - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(matrix[mid/m][mid%m] == target) // creating 2D index from 'mid' and 'm'
                return true;
            else if(matrix[mid/m][mid%m] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
