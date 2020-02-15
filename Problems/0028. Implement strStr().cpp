class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle); <- 1-line STL solution
        int m=haystack.length(), n=needle.length();
        for(int i=0;i<=m-n;i++){
            int j=0;
            for(;j<n;j++){
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==n)
                return i;
        }
        return -1;
    }
};
