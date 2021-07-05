#define ic pair<int, char>
class Solution {
public:
    /* CONSIDER
        'a' as largest no. 
        'b' as medium no.
        'c' as smallest no.
        
        we take 2 or a chars of aa
        if(use_a >= b)  1 char of b is taken
        
        recursively call the func..updating 'a' and 'b' values
        BASE cases will arrange them accordingly
    */
    string longestDiverseString(int a, int b, int c, char aa='a', char bb='b', char cc='c') {
        //cases to make a>=b>=c
        if(a<b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if(b<c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        //BASE CASE
        if(b == 0)
            return string(min(2, a), aa); // return 1 or 2 chars if possible
        
        int use_a = min(2, a);
        int use_b = (a - use_a >= b) ? 1 : 0;
        return string(use_a, aa) + string(use_b, bb) +
                longestDiverseString(a-use_a, b-use_b, c, aa, bb, cc);
    }
};
