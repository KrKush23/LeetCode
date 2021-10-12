class Solution {
public:
    string getPermutation(int n, int k) {
        // initailization ===========
        int fact{1};
        vector<int> nums(n);
        
        for(int i=1; i<n; i++){
            fact *= i;
            nums[i-1] = i;
        }
        nums[n-1] = n;
        
        // solution =================    
        string res{};
        k = k - 1; // for 0 based indexing
        while(true){
            res = res + to_string(nums[k/fact]);
            nums.erase(nums.begin() + k / fact);
            
            if(nums.empty())
                break;
            
            k %= fact;
            fact /= nums.size();
        }
        
        return res;
    }
};
