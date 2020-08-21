class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // ========== using another array =============
        // int n=A.size(), l{0}, r{n-1};
        // vector<int> res(n);
        // for(auto i:A){
        //     if(i&1) res[r--]=i;
        //     else    res[l++]=i;
        // }
        // return res;
        
        // =========  INPLACE  ==============
        int i=0, n=A.size(), j=n-1;
        while(i<j){
            while(A[i]%2==0 and i<j)    i++;
            while(A[j]&1 and i<j)       j--;
            swap(A[i],A[j]);
        }
        return A;
    }
};
