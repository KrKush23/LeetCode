class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m{};
        for(auto i:nums1)
            m[i]++;
        vector<int> ans{};
        for(auto i:nums2){
            if(m.find(i)!=m.end() and m[i]>0){
                m[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
