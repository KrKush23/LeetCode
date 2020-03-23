class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int l{0}, h{0};
        for(auto i:nums){
            l = ~h & (l^i);
            h = ~l & (h^i);
        }
        return l;
    }
};
/*
Because every number will appear three times except only one, we need two bits to save the 3 states of all elements. Our goal is to design a logic operation that will be transformed by following this rule: 00 -> 01 -> 10 -> 00. Let’s assume the input is i , the low bit be l, the high bit be h, the new low bit be l’ and the new high bit be h’. We can draw the truth table of the 3 states as follow:

h | l | i | h'| l'
-------------------
0 | 0 | 0 | 0 | 0    => no input, no change
-------------------  
0 | 1 | 0 | 0 | 1    => no input, no change
-------------------
1 | 0 | 0 | 1 | 0    => no input, no change
-------------------
0 | 0 | 1 | 0 | 1    => 00 -> 01
-------------------
0 | 1 | 1 | 1 | 0    => 01 -> 10
-------------------
1 | 0 | 1 | 0 | 0    => 10 -> 00

By above truth table, we can compute h' and l' by h , l and i:

h' = h & ~l & ~i | ~h & l & i with third and fifth rows of truth table

l' = ~h & l & ~i | ~h & ~l & i with second and forth rows of truth table

And the later can further be reduced to:

l' = ~h & (l ^ i) — formula 1.

Moreover, if we let l' be assigned first, h' can also be computed by l':

h' = h & ~i & ~l' | ~h & i & ~l' with third and fifth rows of truth table

which is also equal to

h' = ~l' & (h ^ i) — formula 2.

By formula 1 and 2, we can easily extract the only single one by taking low bit, which means the number whose state still remains 01.
*/
