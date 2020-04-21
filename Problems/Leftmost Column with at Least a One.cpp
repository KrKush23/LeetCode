/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> sides = binaryMatrix.dimensions();
        int ans{sides[1]}, rows{sides[0]}, cols{sides[1]-1};
        int row{0}, col{cols};
        while(row < rows and col >= 0){
            if(binaryMatrix.get(row, col)==1)
                col--;
            else
                row++;
        }
        return (col==cols)? -1:col+1;
    }
};
