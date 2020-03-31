class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m1{},m2{};
        int bulls{},cows{}, n= secret.length();
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        for(auto i:m1){
            if(m2.find(i.first) != m2.end())
                cows += min(m1[i.first], m2[i.first]);
        }
        string ans{""};
        ans+= to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
