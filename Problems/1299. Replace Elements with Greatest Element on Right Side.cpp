class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.empty())  return {};
        vector<int> ans{arr};
        int n=arr.size();
        int last_max{ans[n-1]},temp{};
        ans[n-1] = (-1);
        for(int i=n-2; i>=0;i--){
            temp = last_max;
            last_max = max(last_max,ans[i]);
            ans[i]=temp;
        }
        return ans;
    }
};
