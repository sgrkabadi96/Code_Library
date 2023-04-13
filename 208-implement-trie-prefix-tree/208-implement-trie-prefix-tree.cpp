class Trie {
public:
    struct TrieNode {
        char data ; 
        TrieNode* child[26] ;
        bool isEnd ;
    };
    
    TrieNode * root ;
    
    
    TrieNode* getNode(char val){
        TrieNode* newnode = new TrieNode; 
        newnode->data = val;
        newnode->isEnd = false;
        for(int i = 0 ; i < 26 ; i++){
            newnode->child[i] = NULL;
        }
        return newnode;
    }
    
    Trie() {
        root = getNode('/');
    }
    
    void insert(string word) {
        TrieNode* curr = root ; 
        for(char &c : word) {
            if(curr->child[c-'a'] == NULL) {
                curr->child[c-'a'] = getNode(c);
            }
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true ;
    }
    
    
    bool search(string word) {
        TrieNode* curr = root ; 
        
        for(char &c : word){
            if(curr->child[c-'a'] == NULL) return false;
            curr = curr->child[c-'a'];
        }
        return curr->isEnd == true;
    }
    
    bool startsWith(string word) {
        TrieNode* curr = root ; 
        
        for(char &c : word){
            if(curr->child[c-'a'] == NULL) return false;
            curr = curr->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */