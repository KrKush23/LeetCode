class Solution {
public:
    int hammingDistance(int x, int y) {
        //========== FASTER WAY ==========
        int a = x^y;
        vector<int> bin(32,0);
        int i{0};
        while(a>0){
            bin[i++] = a%2;
            a/=2;
        }
        int cnt{0};
        for(auto i:bin)
            if(i&1)
                cnt++;
        return cnt;
        //============ MY WAY ===========
        // int cnt{},temp{};
        // for(int i=0;i<32;i++){
        //     temp = 1<<i;
        //     if((x&temp)^(y&temp))
        //         cnt++;
        // }
        // return cnt;
    }
};
