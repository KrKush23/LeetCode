class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if(m>n) 
            return 0;
        
        vector<int> m1(26), m2(26);
        //Creating window of appropriate size
        for(int i=0;i<m;i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        
        //Sliding the window
        for(int i=m;i<n;i++){
            if(m1==m2)  return 1;
            
            m2[s2[i-m]-'a']--;
            m2[s2[i]-'a']++;
        }
        return m1 == m2;
    }
};
