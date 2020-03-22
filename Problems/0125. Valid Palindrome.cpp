class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j = s.length()-1;
        while(i<=j){
            if(isalnum(s[i]) and isalnum(s[j])){
                if(tolower(s[i++]) != tolower(s[j--]))
                    return false;
            }
            else if(!isalnum(s[i]))
                i++;
            else
                j--;
        }
        return true;
    }
};
