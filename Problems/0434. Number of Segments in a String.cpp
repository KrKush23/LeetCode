class Solution {
public:
    int countSegments(string s) {
        int ans{}, n = s.length();
        for(int i=0;i<n;i++){
            if((i==0 || s[i-1]==' ') and s[i] != ' ')
                ans++;
        }
        //count no. of starts for a segment
        return ans;
    }
};
