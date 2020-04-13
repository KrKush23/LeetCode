class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), start{}, max_length{}, max_count{};
        vector<int> count(26,0);        
        for(int end=0;end<n;end++){
            max_count = max(max_count, ++count[s[end]-'A']);        //count of most occuring char in the window
            while(end-start-max_count+1 > k)        //window_size = end-start+1
                count[s[start++]-'A']--;            //decreasing window size when replaceable chars > k and the corresponding coount
            max_length = max(max_length, end-start+1); 
        }
        return max_length;
    }
};
