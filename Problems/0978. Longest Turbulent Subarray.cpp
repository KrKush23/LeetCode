class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int up{1}, down{1};
        int res{1};
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > arr[i-1]){
                up = down + 1;
                down = 1;
                res = max(res, up);
            }else if(arr[i] < arr[i-1]){
                down = up + 1;
                up = 1;
                res = max(res, down);
            }else{
                up = down = 1;
            }
        }
        
        return res;
    }
};

// 376. Wiggle Subsequence
