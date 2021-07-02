class Solution {

public:
	int scheduleCourse(vector<vector<int>>& courses) {
		// SORTING the 2D vector ====================
		// sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
		//     return a[1] < b[1];
		// });

		// SORTING by making vector<pair<int, int>> ========
		// faster than sorting 2D vectors
		vector<pair<int, int>> v;
		for (auto c : courses)
			v.push_back({c[1], c[0]});
		sort(v.begin(), v.end());


		// PRIORITY QUEUE ================
		priority_queue<int> pq;
		int time{0};

		for (auto [deadline, duraton] : v) {
			if (time + duraton <= deadline) {               // IF possible..take the course
				pq.push(duraton);
				time += duraton;
			} else if (!pq.empty() and pq.top() > duraton) { // if this course is shorter than any..take this
				time += duraton - pq.top();
				pq.pop();
				pq.push(duraton);
			}
		}
		return pq.size();
		// MEMOIZATION - TLE =============
		/*
		int n = courses.size();
		int m = courses[n-1][1];
		vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

		return helper(courses, 0, 0, dp);
		*/
	}
	/* FOR MEMOIZATION ===============
	int helper(vector<vector<int>>& courses, int i, int time, vector<vector<int>>& dp){
	    if(i == courses.size())
	        return 0;
	    if(dp[i][time] != -1)
	        return dp[i][time];

	    int taken {0};
	    if(time + courses[i][0] <= courses[i][1])
	        taken =  1 + helper(courses, i+1, time+courses[i][0], dp);

	    int not_taken = helper(courses, i+1, time, dp);

	    return dp[i][time] = max(taken, not_taken);
	}
	*/
};
