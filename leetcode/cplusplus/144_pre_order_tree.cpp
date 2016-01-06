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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
            
        res.push_back(root->val);
        if(root->left!=NULL){
            vector<int> left = preorderTraversal(root->left);
            res.insert(res.end(),left.begin(),left.end());
        }
        
        
        if(root->right!=NULL){
            vector<int> right = preorderTraversal(root->right);
            res.insert(res.end(),right.begin(),right.end());
        }
        return res;
    }
};
