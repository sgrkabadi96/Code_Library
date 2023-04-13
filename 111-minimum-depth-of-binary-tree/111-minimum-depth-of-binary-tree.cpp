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
    
    int helper(TreeNode* root){
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        return min(l , r) + 1;
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return helper(root);
    }    
};