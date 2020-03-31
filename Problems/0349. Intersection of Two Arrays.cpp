class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //unordered_set is FASTER THAN set
        //assigning set with the elements of a vector
        unordered_set<int> s(nums1.begin(),nums1.end());
        vector<int> ans{};
        for(auto i: nums2)
            if(s.find(i)!=s.end()){
                s.erase(i);
                ans.push_back(i);
            }
        return ans;
    }
};
