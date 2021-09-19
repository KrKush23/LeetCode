class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        if(jug1 + jug2 < target)
            return false;
        if(jug1 == target or jug2 == target or jug1 + jug2 == target)
            return true;
            
        // IF target can be divided by GCD(jug1, jug2) => POSSIBLE
        return target % __gcd(jug1, jug2) == 0;
    }
};
