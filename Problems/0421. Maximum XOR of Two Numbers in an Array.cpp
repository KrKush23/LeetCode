struct trieNode{
    trieNode* left;
    trieNode* right;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Insertion into TRIE
        trieNode* root = new trieNode();
        for(auto i:nums)
            insert(i, root);
        
        // Solving using the TRIE
        int ans{INT_MIN};
        for(auto i:nums){
            trieNode* cur{root};
            int cur_xor{0};
            
            // Trie tries to change bits to get MAXm XOR if path is available
            for(int j=31;j>=0;j--){
                if((i>>j)&1){   //bit is 1
                    if(cur->left){
                        cur = cur->left;
                        cur_xor += pow(2,j);
                    }else{
                        cur = cur->right;
                    }
                }else{          //bit is 0
                    if(cur->right){
                        cur = cur->right;
                        cur_xor += pow(2,j);
                    }else{
                        cur = cur->left;
                        
                    }
                }
            }
            ans = max(ans, cur_xor);
        }
        
        return ans;
    }
private:
    void insert(int n, trieNode* root){
        trieNode* cur{root};
        
        // Trie follows path as of bits
        for(int i=31; i>=0; i--){
            if((n>>i)&1){   // bit is 1
                if(!cur->right)
                    cur->right = new trieNode();
                cur = cur->right;
            }else{          // bit is 0
                if(!cur->left)
                    cur->left = new trieNode();
                cur = cur->left;
            }
        }
    }
};

// NOTE : can use ptr to children array instead of two ptrs
//        and take benefit of set bit is accessing the children in array
