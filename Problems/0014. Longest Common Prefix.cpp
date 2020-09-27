class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            if (ans == "")
                return "";
            int j = 0;
            for (; j < ans.length() and j < strs[i].length(); j++){
                if (ans[j] != strs[i][j])
                    break;
            }
            ans = ans.substr(0, j);
        }

        return ans;
    }
};
