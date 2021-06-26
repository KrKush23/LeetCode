class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        for(int i=0, j=n-1; i<j; i++, j--){
            if(s[i] != s[j]){       //when char doesn't match
                return isPalindrome(s, i+1, j) or isPalindrome(s, i, j-1); //check if any of the two is PALINDROME
            }
        }
        return true;
    }
    // function to check if a string is PALINDROME
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
