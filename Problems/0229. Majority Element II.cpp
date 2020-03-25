class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //======== USING BOYER–MOORE MAJORITY VOTE ALGORITHM =======
        
        /*  Since we need occurences greater than n/3 
            Therefore, we made triplets of different nos. and 
            counted the nos. which have duplicates left 
        */
        int x{-1}, y{-1}, cntx{0}, cnty{0}, n=nums.size();
        for(auto i:nums){
            if(i==x)         cntx++;
            else if(i==y)   cnty++;
            else if(!cntx)  {x=i; cntx=1;}
            else if(!cnty)  {y=i; cnty=1;}
            else            {cntx--;cnty--;}
        }
        cntx = cnty = 0;
        for(auto i:nums){
            if(i==x)
                cntx++;
            else if(i==y)
                cnty++;
        }
        vector<int> ans{};
        if(cntx > n/3)    ans.push_back(x);
        if(cnty > n/3)    ans.push_back(y);
        return ans;
        
    }
};
