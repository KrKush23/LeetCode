#define F first
#define S second
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        map<int, int> m{};
        for (auto i : nums)
            m[i]++;

        int res{};
        for (auto i : m) {
            if (k == 0) {
                if (i.S > 1)   res++;
            } else if (m.count(i.F + k)) {
                res++;
            }
        }
        return res;
    }
};
