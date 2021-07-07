class Solution {
    int m, n;
    int countLessEqual(int mid){
        int cnt = 0;
        for(int i=1; i<=m; i++) //for each row...count no.of elements <= mid
            cnt += min( mid / i, n);
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        this->m = m, this->n=n;
        int l=1, r = m*n;
        while(l<r){
            int mid = l + (r-l)/2;
            if(countLessEqual(mid) < k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};

// SIMILAR to
// 378. Kth Smallest Element in a Sorted Matrix
