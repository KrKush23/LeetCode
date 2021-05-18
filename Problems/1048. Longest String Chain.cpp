#define len(x) (int)x.length()
#define sz(x) (int)x.size()
class Solution {
	// Recursion and Memoization
	// == == == == == == == == == == == == == == == == == == ==
// 	int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string curWord) {
// 		if (memo.find(curWord) != memo.end())
// 			return memo[curWord];

// 		int maxLen{1};
// 		for (int i = 0; i < len(curWord); i++) {
// 			// Creating all one lesser length substrings
// 			string newWord = curWord.substr(0, i) + curWord.substr(i + 1);

// 			if (words.find(newWord) != words.end()) {
// 				int curLen = 1 + dfs(words, memo, newWord);
// 				maxLen = max(maxLen, curLen);
// 			}
	// }
// 		// Memoization
// 		memo[curWord] = maxLen;
// 		return maxLen;
// 	}
// public:
// 	int longestStrChain(vector<string>& words) {
// 		unordered_map<string, int> memo{};
// 		unordered_set<string> wordsPresent(words.begin(), words.end());
// 		int res{0};

// 		for (const auto &word : words) {
// 			res = max(res, dfs(wordsPresent, memo, word));
// 		}

// 		return res;
// 	}

	// Tabular DP (Bottom Up)
	// == == == == == == == == == == == == == == == =
public:
	int longestStrChain(vector<string>& words) {
		unordered_map<string, int> dp{};
		sort(words.begin(), words.end(), [](string a, string b) {return len(a) < len(b);});
		int maxLen{1};

		for (auto word : words) {
			int curLen {1};
			for (int i = 0; i < len(word); i++) {
				string newWord = word.substr(0, i) + word.substr(i + 1);
				if (dp.find(newWord) != dp.end()) {
					curLen = max(curLen, dp[newWord] + 1);
				}
				dp[word] = curLen;
				maxLen = max(maxLen, curLen);
			}
		}

		return maxLen;
	}
};
