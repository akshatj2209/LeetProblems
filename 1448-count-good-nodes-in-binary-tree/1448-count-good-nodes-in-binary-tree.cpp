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
    int recur(TreeNode* root, int value){
        if(root==NULL){
            return 0;
        }
        if(root->val>=value){
            return 1+recur(root->left,root->val)+recur(root->right,root->val);
        }
        return recur(root->left,value)+recur(root->right,value);
    }
    int goodNodes(TreeNode* root) {
        return recur(root, -10001);
        
    }
};