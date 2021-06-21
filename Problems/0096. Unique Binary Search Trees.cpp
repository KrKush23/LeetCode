class Solution {
	vector<int> dp;
public:
	int uniqueBST(int n) {
		// BASE CASE
		if (n == 0 or n == 1)
			return 1;

		// MEMOIZATION
		if (dp[n] != -1)
			return dp[n];

		//RECURSIVE
		int res{0};
		for (int i = 1; i <= n; i++) { // selecting each node one by one
			res += uniqueBST(i - 1) * uniqueBST(n - i); // will have (i-1)LEFT NODES and (n-i)RIGHT NODES
		}
		return dp[n] = res;
	}
	int numTrees(int n) {
		// MEMOIZATION ================
		dp.resize(n + 1, -1);
		return uniqueBST(n);

		// TABULAR ====================
		//CATALAN NUMBERS
		if (n < 2)
			return n;
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++) // finding unique BSTs for i nodes
			for (int j = 0; j < i; j++)
				dp[i] += dp[j] * dp[i - j - 1]; //select each node one by oneas root..solving subproblems
		return dp[n];
	}
};
