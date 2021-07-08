class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res{};
        
        //PATTERN  bases ====================================
        for(int i=0; i<l.size(); i++){
            if(r[i] - l[i] < 2){
                res.push_back(true);
                continue;
            }
            
            int len   = r[i] - l[i] + 1;
            int min_e = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int max_e = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            
            if(min_e == max_e)
                res.push_back(true);
            else if((max_e - min_e) % (len - 1))
                res.push_back(false);
            else{
                vector<bool> val(len);
                int diff = (max_e - min_e) / (len-1); //diff between each
                int j;
                
                for(j=l[i]; j<=r[i]; j++){
                    if((nums[j] - min_e) % diff || val[(nums[j] - min_e) /diff])
                        break;
                    val[(nums[j] - min_e) / diff] = true;
                }
                res.push_back( j > r[i]);
            }
            
        }
                
        // SORTing based ========================================
        /*
        for(int i=0; i<l.size(); i++){
            if(l[i] == r[i])
                continue;
            
            vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1); // get the reqd subarray
            sort(v.begin(), v.end());                                    // sort it
            
            bool flag = true;
            for(int i=2; i<v.size(); i++){
                if(v[i] - v[i-1] != v[1] - v[0]){
                    flag = false;
                    break;
                }
            }
            res.push_back(flag);    
        }
        */
        
        return res;
    }
};
