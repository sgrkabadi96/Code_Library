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
    
    TreeNode* helper(vector<int> &pre ,int ps , int pe , vector<int> in , int is , int ie){
        if(ps > pe ) return NULL;
        
        int k;
        for( k = is ; k <= ie ; k++){
            if(pre[ps] == in[k]){
                break;
            }
        }
        int count = k - is;
        TreeNode* root = new TreeNode(pre[ps]);
        root->left =  helper(pre , ps+1, ps+count , in , is , k-1);
        root->right = helper(pre , ps+count+1 , pe , in , k+1 , ie) ;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        if(n == 0) return NULL;
        return helper(preorder , 0 , n-1 , inorder , 0 , n-1 );
        
    }
};