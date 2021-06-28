class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt{0};
        int left{0}, right{0};
        for(auto i:s){
            if(i == 'L')
                left++;
            else
                right++;
            if(left == right)
                cnt++;
        }
        return cnt;
    }
};
