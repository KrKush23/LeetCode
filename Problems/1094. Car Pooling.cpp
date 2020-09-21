#define F first
#define S second
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops (1001,0);
        for(auto i:trips){
            stops[i[1]] += i[0];
            stops[i[2]] -= i[0];
        }
        int cur{0};
        for(auto i:stops){
            cur += i;
            if(cur>capacity)
                return 0;
        }
        return 1;
        
    }
};
