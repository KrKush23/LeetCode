class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans{};
        for(int i=left;i<=right;i++){
            int n{i};
            while(n){
                int d = n%10;
                n/=10;
                if(d==0 or i%d!=0)
                    goto x;
            }
            if(n==0)   ans.push_back(i);  
            x:;
        }
        return ans;
    }
};
