class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> m{};
        vector<vector<int>> res{};
        
        // METHOD 1. MAKING res..while pushing into map ====================
        for(int i=0; i<groupSizes.size(); i++){
            m[groupSizes[i]].push_back(i);
            if(m[groupSizes[i]].size() == groupSizes[i]){
                res.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
        
        
        // METHOD 2. MAking map....making res after it =====================
        for(int i=0; i<groupSizes.size(); i++)
            m[groupSizes[i]].push_back(i);
    
        for(auto c: m){
            auto [sz, nums] = c;
            int i=0, n=nums.size();

            while(i<n){
                vector<int> temp{};
                for(int j=i; j<i+sz; j++){
                    temp.push_back(nums[j]);
                }
                res.push_back(temp);
                i += sz;
            }
        }
        
        
        return res;
    }
};
