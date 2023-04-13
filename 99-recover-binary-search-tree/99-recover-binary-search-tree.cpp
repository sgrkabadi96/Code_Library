/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root , TreeNode*& prev , TreeNode* &f , TreeNode*& s){
        if(root == NULL) return ;
        helper(root->left , prev , f  , s);
        
        if(prev){
            if(root->val < prev->val) {
                if(f == NULL) {
                    f = prev ;
                } 
                s = root;
            }
        }
        
        prev = root ;
        helper(root->right , prev , f , s);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL , *f = NULL , *s = NULL ;
        helper(root , prev , f , s );
        swap(f->val , s->val);
    }
        
    
};