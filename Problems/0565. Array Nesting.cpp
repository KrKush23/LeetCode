class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res{};
        
        // EXTRA SPACE - O(n) space with VIS array ==============
        /*
        vector<bool> vis(nums.size());
        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                int cur = i;
                int cnt = 0;
                while(!vis[cur]){
                    vis[cur] = 1;
                    cur = nums[cur];
                    cnt++;
                }
                
                res = max(res, cnt);
            }
        }
        */
        
        // O(1) space - replace visited places with INT_MAX =========
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != INT_MAX){
                int cur = i;
                int cnt = 0;
                
                while(nums[cur] != INT_MAX){
                    int temp = cur;
                    cur = nums[cur];
                    nums[temp] = INT_MAX;
                    cnt++;
                }
                
                res = max(res, cnt);
            }
        }
        
        return res;
    }
};
