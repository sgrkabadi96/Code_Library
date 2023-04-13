/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool gotBoth = false;
    bool gotp = false;
    bool gotq = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL ;
        if(root->val == p->val ){
            gotp = true;
            return root;
        }
        if(root->val == q->val){
            gotq = true;
            return root;
        }
       
        
        TreeNode* l =lowestCommonAncestor(root->left , p ,q );
        TreeNode* r = lowestCommonAncestor(root->right , p ,q );
        
        if(l && r && gotBoth == false ) {
            gotBoth = true;
            return root;
        }
        
        if(l ) return l;
        if(r) return r;
        return NULL;
    }
};