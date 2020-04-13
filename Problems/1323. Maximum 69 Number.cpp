class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(auto &i:s){
            if(i=='6'){
                i='9';
                return stoi(s);
            }
        }
        return num;
    }
};
