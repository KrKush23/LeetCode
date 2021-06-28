class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n, 0);
        
        // "move" balls from left to right, and track how many ops it takes for each box.
        // For that, we count how many balls we got so far in cnt, and accumulate it in ops.
        // Then, same from right to left.
        
        // LEFT to RIGHT
        for(int i=0, cnt=0, ops=0; i<n; i++){
            res[i] += ops;
            cnt += (boxes[i] == '1') ? 1:0;
            ops += cnt;
        }
        // RIGHT to LEFT
        for(int i=n-1, cnt=0, ops=0; i>=0; i--){
            res[i] += ops;
            cnt += (boxes[i] == '1') ? 1:0;
            ops += cnt;
        }
        
        return res;
    }
};
