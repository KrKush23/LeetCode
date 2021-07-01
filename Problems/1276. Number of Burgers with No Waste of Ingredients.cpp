class Solution {
public:
    vector<int> numOfBurgers(int t, int c){
        if(t&1 or t < c*2 or t > c*4)
            return {};
        return {t/2 - c, c*2 - t/2};
    }
    // jumbo + small = cheese
    // jumbo*4 + small*2 = tomato
    
    // -> jumbo = tomato / 2 - cheese
    // -> small = cheese*2 - tomato/2
};
