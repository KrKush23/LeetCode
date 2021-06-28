class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int res = 0;
        for (auto i : nums) //create counter
            if (i < k)
                counter[i]++;
            
        for (auto [i, cnt] : counter) //check in counter for(k-i)
            if (counter.count(k - i))
                res += min(counter[k - i], cnt);
    
        return res/2; // cz we counted two times
        
        // SORTING ===========================
        /*
        sort(nums.begin(), nums.end());
        
        int res{}, n = nums.size();
        int i=0, j=n-1;
        
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum > k)
                j--;
            else if(sum < k)
                i++;
            else{
                res++;
                i++; j--;
            }
        }
        return res;
        */
    }
};
