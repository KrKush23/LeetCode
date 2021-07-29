#define vi vector<int>::iterator
#define vivi pair<vi, vi>

#define F first
#define S second

struct comp{
    bool operator()(vivi a, vivi b){
        return *a.F > *b.F;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int lo = INT_MAX, hi = INT_MIN; 
        
        // min heap of ITERATORs of each row...sorted based on their values of 1st iterator in the pair
        priority_queue<vivi, vector<vivi>, comp> pq; // MIN HEAP
        
        // filling heap with 1st element of each list
        for(auto &row:nums){
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        
        vector<int> res {lo, hi};
        
        while(true){
            // remove top;
            auto cur = pq.top();
            pq.pop();
            
            cur.F++;
            if(cur.F == cur.S) // at least 1 list completely traversed
                break;
            // push next of smallest
            pq.push(cur);
            
            // now compare the range
            lo = *pq.top().F;       // lowest in HEAP (1st one)
            hi = max(hi, *cur.F);   // previuos 'hi' or the newest element in HEAP
            
            if(hi - lo < res[1] - res[0])
                res = {lo, hi};
        }
        return res;
    }
};

 // NOTE: we need iterators because ALL LISTS ARE NOT OF THE SAME SIZE
