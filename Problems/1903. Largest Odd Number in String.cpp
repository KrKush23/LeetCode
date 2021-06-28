class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length() - 1; i>=0; i--){
            if((num[i] - '0') & 1)
                return num.substr(0, i+1);
        }
        return "";
        
        // ONE LINER
        return num.substr(0, num.find_last_of("13579") + 1);
    }
};
