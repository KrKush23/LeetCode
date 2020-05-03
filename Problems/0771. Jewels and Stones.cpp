class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels{};
        for(auto i:J)
            jewels.insert(i);
        int res{};
        for(auto i:S){
            if(jewels.find(i)!=jewels.end())
                res++;
        }
        return res;
    }
};
