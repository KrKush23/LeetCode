class Solution {
    vector<string> res;
public:
    bool isValid(string s){
        int cnt{0};
        for(auto ch : s){
            if(ch == '(') cnt++;
            if(ch == ')') cnt--;
            if(cnt < 0) return false;
        }
        
        return cnt == 0;
    }
    
    void dfs(string s, int start, int l, int r){
        // nothing to remove
        if(l==0 and r==0){
            if(isValid(s))
                res.push_back(s);
            return;
        }
        
        for(int i=start; i< s.length(); i++){
            // we only remove 1st parenthesis if there are consecutive
            // ones, to avoid duplication
            if(i != start && s[i] == s[i-1]) 
                continue; //we go to next char to avoid duplication
            
            // we remove the bracket(any)
            if(s[i] == '(' or s[i] == ')'){
                string cur = s;
                cur.erase(i,1);
                
                // adjust r/l based on removed bracket
                if(r>0 and s[i] == ')')
                    dfs(cur, i, l , r-1);
                else if(l>0 and s[i] == '(')
                    dfs(cur, i, l-1, r);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        // l/r: number of left/right parentheses to remove.
        int  l{0}, r{0};
        
        for(auto ch : s){
            l += (ch == '(');
            if(l==0)
                r += (ch == ')');
            else
                l -= (ch == ')');
        }
        
        dfs(s, 0, l, r);
        return res;
    }
};
