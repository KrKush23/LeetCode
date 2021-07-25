class Solution {
public:
    int findIntegers(int n) {        
        int f[32] = {0};
        f[0] = 1;
        f[1] = 2;
        
        for(int i =2; i< 32;i++)
            f[i] = f[i-1]+f[i-2];
        
        int res = 0;
        int k = 30;
        int theLastDigit = 0;
        
        while(k >= 0){
            // if 'K+1'th bit is 1
            if(n&(1<<k)){
                res += f[k];  // add f[k] to res
                if(theLastDigit) // 2 consecutive 1's FOUND..no need to go ahead
                    return res;
                theLastDigit =1; // update 
            }else{
                theLastDigit =0; // update
            }
            
            k--;
        }
        
        return res+1; // plus 1...if whole loop runs...we count given no. too
    }
};
