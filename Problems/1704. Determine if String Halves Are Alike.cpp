class Solution {
public:
	// 1st Way =================

	bool halvesAreAlike(string s) {
		int res{}, n = s.length();
		vector<char> symbols{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

		for (int i = 0, j = n / 2; j < n; i++, j++) {
			if (find(symbols.begin(), symbols.end(), s[i]) != symbols.end())
				res++;
			if (find(symbols.begin(), symbols.end(), s[j]) != symbols.end())
				res--;
		}
		return !res;
	}


    // 2nd Way =================

	// bool halvesAreAlike(string s) {
	// 	int n = s.length();
	// 	string s1 = s.substr(0, n / 2), s2 = s.substr(n / 2, n / 2) ;
	// 	return helper(s1) == helper(s2);
	// }

	// int helper(string s) {
	// 	int sum{};
	// 	for (auto c : s) {
	// 		c = toupper(c);
	// 		if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
	// 			sum++;
	// 	}
	// 	return sum;
	// }
};
