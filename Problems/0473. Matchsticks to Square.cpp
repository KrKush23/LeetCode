class Solution {
    int target;
    vector<int> partition;
public:
    bool backtrack(int idx, vector<int>& matchsticks){
        // BASE CASE - all elements have been traversed
        if(idx == matchsticks.size()){
            for(auto i:partition)
                if(i != target) //all partitions sould have reached TARGET value
                    return false;
            return true;
        }
        
        //RECURSIVE CASE
        //TRY placing CURRENT ELEMENT in each partition one by one
        for(auto &i:partition){
            if(i + matchsticks[idx] <= target){
                // 1. ADD in current partition
                // 2. CALL for NEXT ELEMENT
                // 3. REMOVE from current partition
                i += matchsticks[idx]; 
                if(backtrack(idx+1, matchsticks))
                    return true;
                i -= matchsticks[idx]; //backtracking
                
            }
            
            if(i == 0) //CURRENT ELEMENT is larger than TARGET
                break;
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        // Variation of 698. Partition to K Equal Sum Subsets
        // WHERE  K = 4
        partition.resize(4, 0);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(matchsticks.size()<4 or sum%4)
            return false;
        
        target  = sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend()); // LARGER ELEMENTS will be placed EARLIER THAN smaller ones
        return backtrack(0, matchsticks);
    }
};
