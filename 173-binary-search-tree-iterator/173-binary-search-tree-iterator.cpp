/**
 * Definition for a binary tree node.
 * struct TreeNode {
https://leetcode.com/problems/binary-search-tree-iterator/submissions/ *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> a ;
    int idx = -1 ;
    
    void inorder(TreeNode* root ){
        if(root == NULL) {
            return ;
        }
        inorder(root->left );
        a.push_back(root->val);
        inorder(root->right );
    }
    BSTIterator(TreeNode* root) {
        inorder(root) ;
    }
    
    int next() {
        idx++;
        return a[idx] ;
        
    }
    
    bool hasNext() {
        if(idx == a.size()-1) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */