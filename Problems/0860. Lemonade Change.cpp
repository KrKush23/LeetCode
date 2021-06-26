class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5{0}, cnt10{0};
        for(auto i:bills){
            if(i == 5){
                cnt5++;
            }else if(i == 10){
                cnt10++; cnt5--;
            }else{
                if(cnt10 > 0){
                    cnt10--;    cnt5--;
                }else{
                    cnt5 -= 3;
                }
            }
            if(cnt5 < 0)
                return false;
        }
        return true;
    }
};
