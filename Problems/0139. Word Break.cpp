class Solution {
public:
	bool isPresent(string word, vector<string>& wordDict) {
		for (int i = 0; i < wordDict.size(); i++) {
			if (wordDict[i].compare(word) == 0)
				return true;
		}
		return false;
	}

// BACKTRACKING ====================
    // TLE
// 	bool wordBreak(string s, vector<string> &wordDict) {
// 		int l = s.length();
// 		if ( l == 0) return 1;

// 		for (int i = 1; i <= l; i++) {
// 			if (isPresent(s.substr(0, i), wordDict)
// 			        and  wordBreak(s.substr(i, l - i), wordDict))
// 				return true;
// 		}
// 		return false;
// 	}

// TABULAR =======================
	bool wordBreak(string s, vector<string> &wordDict) {
		int l = s.length();
		if ( l == 0) return true;

		vector<bool> dp(l + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < l; i++) {
			if (!dp[i])
				continue;
			for (int j = i + 1; j <= l; j++) {
				if (isPresent(s.substr(i, j - i), wordDict))
					dp[j] = 1;
			}
		}
		return dp[l];
	}
};
