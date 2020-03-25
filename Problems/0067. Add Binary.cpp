class Solution {
public:
    string addBinary(string a, string b) {
        string ans{};
        int i = a.length()-1, j = b.length()-1, carry{};
        while(i>=0 or j>=0 or carry){
            int sum = carry;
            if(i>=0)    sum += a[i--] - '0';
            if(j>=0)    sum += b[j--] - '0';
            ans += char(sum%2 + '0');
            carry =sum /2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
