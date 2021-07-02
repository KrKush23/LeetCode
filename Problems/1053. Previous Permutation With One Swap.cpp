class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int candid = n-2;
        
        while(candid >= 0 and arr[candid+1] >= arr[candid])
            candid--;
        
        if(candid < 0)  // NO PREVIOUS permutation (sorted)
            return arr;
        
        // FINDING element to be swapped with candid
        int r=candid + 1;
        for(int i=r; i<n; i++){
            if(arr[i] < arr[candid] and arr[i] > arr[r])
                r = i;
        }
        
        swap(arr[candid], arr[r]);
        return arr;
    }
};
