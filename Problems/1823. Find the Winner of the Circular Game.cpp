class Solution {
    vector<int> v{};
    
    int solve(int idx, int n, int k){
        //BASE CASE
        if(n == 1)
            return v[0];
        
        //RECURSIVE CASE
        idx = (idx + k) % n;
        v.erase(v.begin() + idx);
        
        return solve(idx, n-1, k);
    }
public:
    int findTheWinner(int n, int k) {
        // ITERATIVE
        int res = 0;
        for(int i=1; i<=n; i++)
            res = (res + k)% i;
        return res+1;
        
        // SIMULATION (recursion)
        v.resize(n);
        for(int i=0; i<n; i++)
            v[i] = i+1;
        
        return solve(0, n, k-1); // to remove every k-1 th number
    }
};
