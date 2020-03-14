#define pb push_back
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans{};
        int i=0,j=0;
        while(i<m and j<n){
            if(nums1[i]<nums2[j])
                ans.pb(nums1[i++]);
            else
                ans.pb(nums2[j++]);
        }
        while(i<m)
            ans.pb(nums1[i++]);
        while(j<n)
            ans.pb(nums2[j++]);
        nums1=ans;
    }
};
