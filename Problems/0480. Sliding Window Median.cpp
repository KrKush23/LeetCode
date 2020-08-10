class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2); // getting ptr to halfway element
        vector<double> medians;
        for (int i=k; ; i++) {

            // Push the current median.
            medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

            // If all done, return.
            if (i == nums.size())
                return medians;

            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)     //managing MID
                mid--;

            // Erase nums[i-k].
            if (nums[i-k] <= *mid)  //managing MID
                mid++;
            window.erase(window.lower_bound(nums[i-k])); //lower_bound() -> faster than find()
        }
    }
};
