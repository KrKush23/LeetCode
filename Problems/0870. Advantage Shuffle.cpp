class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        //SORT
        multiset<int> s(A.begin(), A.end());
        
        for(int i=0; i<B.size(); i++){
            auto p = (*s.rbegin() <= B[i]) ? s.begin() : s.upper_bound(B[i]); 
            
            A[i] = *p;  // using * to get value of iterator
            s.erase(p); // p give the iterator directly to be deleted
        }
        return A;
    }
    // can apply upper_bound to multiset as S.upper_bound(val);
};
