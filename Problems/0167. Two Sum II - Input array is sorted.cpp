class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //============= USING BINARY SEARCH ==================
        //========= Better Approach than hashing =============
         int i=0, j=numbers.size()-1,sum=0;
        while(i<j){
            sum = numbers[i]+ numbers[j];
            if(sum < target)        i++;
            else if(sum > target)   j--;
            else    break;
        }
        return {i+1, j+1};
        
        //================ USING HASH MAP ===================
        /*map<int,int> m{};
        vector<int> ans(2,-1);
        int n = numbers.size();
        for(int i=0;i<n;i++){
            if(m.find(target - numbers[i])==m.end())
                m[numbers[i]] = i+1;
            else{
                ans[0]=m[target - numbers[i]];
                ans[1]=i+1;
                break;
            }
        }
        return ans;
        */
    }
};
