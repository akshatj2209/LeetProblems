class Solution {
public:
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, pair<int, int>>& memo, int& maxi) {
        if (!root)  return;
        else {
            if (root->left)     dfs(root->left, memo, maxi);
            if (root->right)    dfs(root->right, memo, maxi);
            int lsum = 0, rsum = 0;
            if (root->left) {
                int v1 = memo[root->left].first, v2 = memo[root->left].second;
                int v = root->left->val + max(v1, v2);
                lsum = max(lsum, v);
            }
            if (root->right) {
                int v1 = memo[root->right].first, v2 = memo[root->right].second;
                int v = root->right->val + max(v1, v2);
                rsum = max(rsum, v);
            }
            memo[root] = make_pair(lsum, rsum);
            maxi = max(maxi, root->val + lsum + rsum);
        }
    }
    
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> memo;
        int maxi = INT_MIN;
        dfs(root, memo, maxi);
        return maxi;
    }
};