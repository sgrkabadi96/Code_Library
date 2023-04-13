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
    int countNodes(TreeNode* root) {
        if(root == NULL ) return 0 ;
        
        int leftLevel = 1 ;
        TreeNode* c = root;
        while(c->left){
            c= c->left; leftLevel++;
        } 
        c = root;
        int rightLevel = 1;
        while(c->right) {
            c = c->right ; rightLevel++;
        }
        
        if(leftLevel == rightLevel){
            return (1 << leftLevel) -1 ;
        }        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};