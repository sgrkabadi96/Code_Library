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
    
    bool f(TreeNode* r1 , TreeNode* r2) {
        if(r1 == NULL && r2 == NULL)  return true;
        if(!r1 || !r2 )  return false;
        if(r1->val != r2->val ) return false;
        
        bool x = f(r1->left , r2->right);
        if(!x) return x;
        bool y = f(r1->right , r2->left);
        if(!y) return y;
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        bool check = f(root, root);
        return check;
    }
};