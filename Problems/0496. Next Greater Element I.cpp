class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m{};
        stack<int> st{};
        for(auto i:nums2){
            while(!st.empty() and st.top() < i){
                m[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i])!=m.end())
                ans[i]=m[nums1[i]];
        }
        return ans;
    }
};
