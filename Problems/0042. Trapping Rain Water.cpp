class Solution {
public:
    int trap(vector<int>& height) {
        // Dynamic Programming - SPACE - O(n) =======================================
        /*
        if(height.size()==0)
            return 0;
        
        int n = height.size();
        vector<int> left(n), right(n);
        int res{};

        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for (int i = 1; i < n; i++) 
            left[i] = max(height[i], left[i-1]);
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(height[i], right[i+1]);

        for (int i = 1; i < n-1; i++)
            res += min(left[i], right[i]) - height[i];
        
        return res;
        */
        
        // 2 POINTERS - Space - O(1) ========================================
        int total = 0;
        int left = 0, right = height.size()-1;
        int left_max = 0, right_max = 0;
        
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    total += left_max - height[left];
                left++;
            }else{
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    total += right_max - height[right];
                right--;
            }
        }
        
        return total;
    }
};
