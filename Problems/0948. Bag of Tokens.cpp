class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size() - 1;
        int score{0}, res{0};
        
        while(i<=j){
            if(tokens[i] <= power){         // IF possible to score...SCORE
                power -= tokens[i++];
                res = max(res, ++score);    
            }else if(score > 0){            // IF possible to gain power...GAIN
                power += tokens[j--];
                score--;
            }else{                          // SCORE == 0...BREAK
                return res;
            }
        }
        return res;
    }
};
