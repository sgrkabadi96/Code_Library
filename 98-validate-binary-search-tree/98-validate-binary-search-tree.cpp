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
    
    long long maxx(TreeNode* root){
        if(root == NULL) return LLONG_MIN ;
        long long l = maxx(root->left);
        long long r= maxx(root->right);
        long long c =root->val;
        return max(c , max(l ,r));   
    }
    
    long long minn(TreeNode* root){
        if(root == NULL) return LLONG_MAX;
        long long l = minn(root->left);
        long long r= minn(root->right);
         long long c =root->val;
        return min(c , min(l ,r));   
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right==NULL) return true;
        long long rmin = minn(root->right);
        long long lmax = maxx(root->left);
        if(root->val <= lmax || root->val >= rmin) return false;
        bool l = isValidBST(root->left);
        bool r = isValidBST(root->right);
        if(l == false || r == false) return false;
        return true;
    }
};