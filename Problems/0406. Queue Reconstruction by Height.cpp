class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort in descending order of 'h' and then increasing order of 'people he/she can see'
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
           return (a[0]>b[0] || (a[0]==b[0] and a[1]<b[1])); 
        });
        vector<vector<int>> ans{};
        for(auto i:people){
            ans.insert(ans.begin()+i[1],i); // insert at the position...at which...he can see..no. of people given
        }
        return ans;
    }
};
