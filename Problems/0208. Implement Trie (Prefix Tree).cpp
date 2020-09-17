class Trie {
    vector<Trie*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = 0;
        children.resize(26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur{this};
        for(char c:word){
            int idx = c-'a';
            if(!cur->children[idx])
                cur->children[idx] = new Trie();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur{this};
        for(char c:word){
            int idx = c-'a';
            if(!cur->children[idx])
                return 0;
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur{this};
        for(char c:prefix){
            int idx = c-'a';
            if(!cur->children[idx])
                return 0;
            cur = cur->children[idx];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
