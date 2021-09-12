class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int zeroPos{ -1}, neg1st{ -1};
		int negatives{}, res{};

		for (int i = 0; i < nums.size(); i++) {
            // RESET IF ZERO
			if (nums[i] == 0) {
				negatives = 0;
				neg1st = -1;
				zeroPos = i;
			} else {
				if (nums[i] < 0) { // COUNT if -ve
					negatives++;
					if (neg1st == -1) // mark if 1st -ve
						neg1st = i;
				}

				if (negatives & 1)
					res = max(res, i - neg1st);
				else
					res = max(res, i - zeroPos);
			}
		}
        
		return res;
	}
};
