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
    int recur(TreeNode* root, bool left,map<pair<TreeNode *,bool>, int> &memo){
        if(root==NULL){
            return 0;
        }
        if(memo[{root,left}]!=0){
            return memo[{root,left}];
        }
        if(left){
            return memo[{root,left}]=max(root->val+recur(root->left,false,memo)+recur(root->right,false,memo),recur(root->left,true,memo)+recur(root->right,true,memo));
        }
        return memo[{root,left}]=recur(root->left,true,memo)+recur(root->right,true,memo);
        
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode *,bool>, int> memo; 
        return recur(root,true,memo);
    }
};