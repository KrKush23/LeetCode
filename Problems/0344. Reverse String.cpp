class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=s.size()-1,j=0;i>=j;i--,j++){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
};
