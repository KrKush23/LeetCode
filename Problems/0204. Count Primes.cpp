class Solution {
public:
    int countPrimes(int n) {
        bool primes[n+1];
        memset(primes,1,sizeof(primes));
        // vector<bool> primes(n+1,1);
        // lines 4 and 5 are FASTER than line 6
        for(int i=2; i*i <n; i++){
            if(primes[i]){
                for(int j=i*i; j<n; j+=i)
                    primes[j]=0;
            }
        }
        int count{0};
        for(int i=2;i<n;i++){
            if(primes[i])   
                count++;
        }
        return count;
    }
};
