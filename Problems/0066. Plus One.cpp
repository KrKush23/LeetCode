#define pb push_back
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),i=n-1;
        vector<int> ans{};
        for(;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }
        digits[0]=1;
        digits.pb(0);
        return digits;
    }
};
