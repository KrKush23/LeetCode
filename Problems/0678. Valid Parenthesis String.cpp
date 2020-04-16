class Solution {
public:
    bool checkValidString(string s) {
        //======== GREEDY ==========
        int l{}, h{};
        for(auto c:s){
            l+= (c=='(')?1:-1;  
            h+= (c!=')')?1:-1;
            if(h<0) break;
            l = max(l,0);
        }
        return l==0;
    }
//     if c == '(' -> l++ and h++
//     if c == ')' -> l-- and h--
//     if c == '*' -> l-- and h++
//     if h <0 -> more ')' than '('or'*'
        
//     if l <0 -> more '*' were used as '(' than needed
};
