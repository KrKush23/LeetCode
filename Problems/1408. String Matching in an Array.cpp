class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(), [](string a, string b)
            {return a.size()<b.size();});   //lambda function
        int n=words.size();
        vector<string> ans{};
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].find(words[i]) != words[j].npos){   
                    //npos -> notfound (for string)
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
