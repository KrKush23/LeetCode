class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        int res{};
        
        vector<int> v(m, 0);
        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++){
                (matrix[i][j] == '0') ? v[j] = 0 : v[j]++;
            }
            res = max(res, maxAreaHistogram(v));
        }
        
        return res;
    }
    
    int maxAreaHistogram(vector<int>& heights){
        int n = heights.size();
		vector<int> left(n, -1);
		vector<int> right(n, -1);
		stack<int> st{};

		// next smaller to left
		for (int i = 0; i < n; i++) {
			while (!st.empty() and heights[st.top()] >= heights[i]) {
				st.pop();
			}
			if (st.empty()) {
				left[i] = -1;
			} else {
				left[i] = st.top();
			}
			st.push(i);
		}

		stack<int> e{};
		st = e;

		// next smaller to right
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() and heights[st.top()] >= heights[i]) {
				st.pop();
			}
			if (st.empty()) {
				right[i] = n;
			} else {
				right[i] = st.top();
			}
			st.push(i);
		}

		int res{0};

		for (int i = 0; i < n; i++) {
			int area = (right[i] - left[i] - 1) * heights[i];
			res = max(res, area);
		}
		return res;
    }
};
