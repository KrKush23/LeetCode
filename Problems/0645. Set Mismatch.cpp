class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m{};
        vector<int> ans(2);
        int n = nums.size();
        n = n*(n+1)/2;
        for(auto i: nums){
            if(m.find(i)!=m.end())
                ans[0]=i;
            else
                m[i]=1;
            n-=i;
        }
        ans[1]=ans[0]+n;
        return ans;
    }
};
