class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> m(26, INT_MAX); // INT_MAX for unspecified order of chars
        for(int i=0; i<order.length(); i++)
            m[order[i] - 'a'] = i;
        
        sort(str.begin(), str.end(), [&m](char a, char b){
            return m[a - 'a'] < m[b - 'a'];
        });
        return str;
    }
};
