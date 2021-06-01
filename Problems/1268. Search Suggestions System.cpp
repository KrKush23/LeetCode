class Solution {
public:
//   BINARY SEARCH IMPLEMENTATION
	vector<vector<string>> suggestedProducts(vector<string> &products,
	string searchWord) {
		vector<vector<string>> res{};
		string prefix{};
		int n = products.size();
		int bsStart {0};

		// to apply lower_bound()
		sort(products.begin(), products.end());

		for (char c : searchWord) {
			prefix += c;
			res.push_back({});

			int start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

			// 3 or (words available to the right) time, and
			// prefix should match the word -> used compare() for it
			// compare() return 0 if matched
			for (int i = start; i < min(start + 3, n) and !products[i].compare(0, prefix.length(), prefix); i++) {
				res.back().push_back(products[i]);
			}

			// to optimize search area
			bsStart = start;
		}
		return res;
	}
};
