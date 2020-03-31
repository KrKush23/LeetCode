class Solution {
public:
    bool canWinNim(int n) {
        return (n%4 != 0);
    }
};
//You can always win a Nim game if the number of stones n in the pile is not divisible by 4.
