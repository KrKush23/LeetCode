class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // NORMAL BFS ==============================        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        
        if(!dict.count(endWord))
            return 0;
        
        q.push(beginWord);
        int ladder = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return ladder;
                dict.erase(word);
                
                for(int j=0; j<word.size(); j++){
                    char c = word[j]; 
                    
                    for(auto k='a'; k<='z'; k++){
                        word[j] = k;
                        if(dict.count(word))
                            q.push(word);
                    }
                    
                    word[j] = c;
                }
                
            }
            
            ladder++;
        }
        return 0;
    }
};
