class Solution {
public:
    bool isHappy(int n) {
        set<int> rec{};
        int temp{};
        while(true){
            while(n!=0){
                temp += pow((n%10),2);
                n/=10;
            }
            if(temp == 1)   return 1;
            if(rec.find(temp)!=rec.end())   return 0;
            rec.insert(temp);
            n=temp;
            temp=0;
        }
        return 0;
    }
};
