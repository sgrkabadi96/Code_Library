class WordDictionary {
public:
    struct TrieNode {
        char val ; 
        bool isEnd = false;
        TrieNode *child[26] = {NULL};
    };
    
    TrieNode* root ; 
    
    TrieNode* getNode(char val){
        TrieNode* node = new TrieNode ; 
        node->val = val ;
        node->isEnd = false;
        return node; 
    }
    WordDictionary() {
        root = getNode('/');
    }
    
    void addWord(string word) {
        TrieNode* curr = root ; 
        
        for(char &c : word){
            if(curr->child[c-'a'] == NULL){
                curr->child[c-'a']= getNode(c);
            }
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true ;
    }
    
    bool dfs(TrieNode* root , string &s , int i  , int n){
        if(i == n ){
            return root->isEnd ;
        }
        
        char c = s[i] ; 
        bool ans = false;
        
        if(c == '.'){
            for(int k = 0 ; k < 26 ; k++){
                if(root->child[k] != NULL){
                    ans = dfs(root->child[k] , s,  i+1 , n );
                    if(ans == true) return true ;
                }
            } 
        } 
        
        else {
            if(root->child[c -'a'] == NULL) return false;
            else return dfs(root->child[c-'a'] , s, i+1 , n );
        }
        
        return false;
        
    }
    bool search(string word) {        
        TrieNode* curr = root; 
        
        return dfs(root , word , 0 , word.size());
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */