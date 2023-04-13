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
    
    bool isP = false;
    bool isQ = false;
    
    bool helper(TreeNode* root , TreeNode* p , TreeNode* q){
        if(root==NULL){
            return false;
        }
        
        if(root->val == p->val ) isP = true;
        if(root->val ==q->val) isQ = true;
        if(isP && isQ) return true;
        bool x=  helper(root->left , p , q);
        if(x )return true;
        x = helper(root->right , p ,q);
        if(x) return true;
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        
        TreeNode* left = lowestCommonAncestor(root->left, p ,q);
        if(left) return left;
        TreeNode* right =lowestCommonAncestor(root->right , p ,q);
        if(right) return right;
        isP = false; isQ = false;
        bool isLCA = helper(root , p ,q);
        if(isLCA) return root;
        return NULL;
    }
};