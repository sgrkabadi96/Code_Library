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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        while(q.size()){
            int s = q.size();
            vector<int> t;
            while(s--){
                TreeNode* f = q.front();
                q.pop();
                t.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};