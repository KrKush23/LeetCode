#define vi vector<int>
class Solution {
    int n;
    int countLessEqual(vector<vector<int>>& matrix, int num){
        int cnt{0};
        for(auto row: matrix){
            int l=0, r=n;
            while(l < r){
                int mid = l + (r-l)/2;
                if(row[mid] <=  num)
                    l = mid+1;
                else
                    r = mid;
            }
            cnt += l;
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        
        // 2 BINARY SEARCH approach ============================
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(l<r){
            int mid = l + (r-l)/2; // find mid
            if(countLessEqual(matrix, mid) < k)  //no. of elements less or equal to mid...
                l = mid+1;                       // if < k..l = mid+1
            else
                r = mid;                         // if >= k..r=mid
        }
        return l;
        
        
        // FAST..but not using the SORTED MATRIx fact===========
        /*
        priority_queue<int> pq; // MAX HEAP
        for(auto i:matrix){
            for(auto j:i){
                if(pq.size()<k)
                    pq.push(j);
                else if(j < pq.top()){
                    pq.pop();
                    pq.push(j);
                }
            }
        }
        return pq.top();
        */
        
        // Kth samllest from multiple SORTED LISTS
        /*
        priority_queue<vi, vector<vi>, greater<vi>> pq; // MIN HEAP
        
        for(int i=0; i<n and i<k; i++)
            pq.push({matrix[i][0], i, 0});
        
        int res{};
        while(k--){
            auto cur = pq.top();
            pq.pop();
            res = cur[0];
            int i=cur[1], j=cur[2];
            if(k==0)
                break;
            
            if(j+1<n)
                pq.push({matrix[i][j+1], i, j+1});
        }
        return res;
        */
    }
};
