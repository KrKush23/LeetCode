class Solution {
public:
	int minAddToMakeValid(string s) {
		int cnt{0};
		int left = 0, right = 0;
		for (auto c : s) {
			if (c == '(') {
				cnt += right;
				right = 0;
				left++;
			} else {
				(left > 0) ? left-- : right++;
			}
		}
		return cnt + right + left;
	}
};
