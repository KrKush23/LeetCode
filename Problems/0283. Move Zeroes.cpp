class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       //================ OPTIMAL ===================
       int last{0},n = nums.size();
       for(int i=0;i<n;i++){
          if(nums[i] !=0)
              swap(nums[last++], nums[i]);
       }
    //=============== SUB-OPTIMAL ================
    /*int last{0},n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] !=0)
                nums[last++] = nums[i];
        }
        for(int i=last;i<n;i++)
            nums[i]=0;
    */
    //======== MY WAY (Not Good Enough) ==========
    /*
        int last{0},cnt{0},n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                cnt++;
            else{
                last = i - cnt;
                nums[last] = nums[i];
            }
        }
        for(int i=last+1;i<n;i++)
            nums[i]=0;
    }
    */
};
