class Solution {
    string s;
    int len;
    vector<string> res;
    
    void backtrack(int idx, int cnt, string cur){
        if(cnt == 4){  // all parts formed
            if(idx == len)  // all digits used
                res.push_back(cur.substr(0, cur.length()-1)); //remove last '.'
            return;
        }
        
        // if digit is '0', we can take just 1 '0'...cz we can't have LEADING ZEROES
        if(s[idx] == '0'){
            backtrack(idx+1, cnt+1, cur + s.substr(idx, 1) + ".");
            return;
        }
        
        // IF NO LEADING ZEROES..try all lengths, i.e. 1, 2, 3
        for(int i=1; i<=3 and idx+i<=len; i++){
            string temp = s.substr(idx, i);
            if(stoi(temp) > 255) //numbers must be <= 255
                continue;
            backtrack(idx+i, cnt+1, cur + temp +".");
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        len = s.length();
        res.clear();
        
        backtrack(0, 0, "");
        return res;
    }
};
