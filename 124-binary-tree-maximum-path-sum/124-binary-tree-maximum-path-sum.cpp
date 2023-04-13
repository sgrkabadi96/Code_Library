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
    int ans = INT_MIN;
    
    int helper(TreeNode* root){
        if(root == NULL) return 0 ;
        if(root->left == NULL && root->right == NULL) {
            ans= max(ans , root->val);
            return root->val;
        }
        
        int tobeRetured = root->val ;
        int left , right;
        
        bool l = false , r = false;
        if(root->left){
            l = true;
            left = helper(root->left);
            ans = max(ans , left);
            ans = max(ans , root->val + left);
            if(tobeRetured < root->val + left){
                tobeRetured = left + root->val;
            }
        }
        
        if(root->right){
            r = true;
            right = helper(root->right);
            ans = max(ans , right);
            ans = max(ans , root->val + right);
            tobeRetured = max(tobeRetured , root->val + right);
        }
        if(l && r){
            ans = max(ans , root->val + right + left);
        }
        
        ans = max(ans , tobeRetured);
        return tobeRetured;
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};