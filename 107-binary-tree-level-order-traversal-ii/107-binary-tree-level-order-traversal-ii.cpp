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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans ; 
        if(root == NULL ) return ans;
    
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            int s = q.size();
            vector<int> x ;
            while(s--){
                TreeNode* f = q.front();
                q.pop();
                if(f->left ) q.push(f->left);
                if(f->right) q.push(f->right);
                x.push_back(f->val);
            }
            ans.insert(ans.begin() , x);
        }
        
        return ans;
        
    }
        
};