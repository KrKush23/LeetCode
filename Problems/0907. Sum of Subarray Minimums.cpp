#define F first
#define S second
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long res{}, mod = 1e9+7;
        stack<pair<int, int>> st1, st2;
        vector<int> left(n), right(n);
        
        // Previous smaller 
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!st1.empty() and st1.top().F > arr[i]){
                cnt += st1.top().S;
                st1.pop();
            }
            st1.push({arr[i], cnt});
            left[i] = cnt;
        }
        
        // Next Smaller
        for(int i=n-1; i>=0; i--){
            int cnt = 1;
            while(!st2.empty() and st2.top().F >= arr[i]){
                cnt += st2.top().S;
                st2.pop();
            }
            st2.push({arr[i], cnt});
            right[i] = cnt;
        }
        
        // adding each number, no. of times it will be the SMALLEST in the SUBARRAY having it
        for(int i=0; i<n; i++){
            res = (res + (long)arr[i] * left[i] * right[i]) % mod;
        }
        
        return res;
    }
};
