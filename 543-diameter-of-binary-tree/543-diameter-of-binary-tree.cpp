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
    int recur(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }
        int lefty=recur(root->left,ans);
        int righty=recur(root->right,ans);
        ans=max(ans, lefty+righty);
        
        return 1+max(lefty,righty);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        ans=max(ans,recur(root->left,ans)+recur(root->right,ans));
        return ans;
    }
};