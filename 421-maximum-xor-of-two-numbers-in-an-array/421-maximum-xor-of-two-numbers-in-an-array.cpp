class Solution {
public:
    
    struct TrieNode {
        public : 
        TrieNode* childs[2] = {NULL};
    };
    
    
    class Trie {
        public: 
        TrieNode* root ;
        Trie() {
            root = new TrieNode();
        }

        void insert(int n){
            TrieNode* curr = root;
            for(int i = 31 ; i >= 0 ; i--){
                int index = (n >> i) & 1 ;
                if(curr->childs[index] == NULL) {
                    curr->childs[index] = new TrieNode();
                } 
                curr = curr->childs[index];
            }
        }
        
        int getValue(int n){
            TrieNode* curr = root;
            int res = 0;
            
            for(int i = 31 ; i >= 0 ; i--){
                int index =( n >> i) & 1 ; 
                index = 1 - index ;
                
                if(curr->childs[index]){
                    res = res << 1 ;
                    res = res | 1 ;
                    curr = curr->childs[index];
                } else {
                    res = res << 1 ;
                    res = res | 0 ;
                    index = 1 - index ;
                    curr =curr->childs[index];
                }
            }
            
            return res;
            
        }
        
        
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0; 
        
        Trie trie;
        for(int &i : nums) trie.insert(i);
        
        for(int &i : nums){
            int currans = trie.getValue(i);
            ans = max(ans ,currans);
        }
        
        return ans ;
    }
};