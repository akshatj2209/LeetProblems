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
    vector<TreeNode*> rec(int l, int r) 
    {
        if (l > r) return {NULL};
        if (l == r) return {new TreeNode(l)};
        
        vector<TreeNode*> ans;
        for (int root = l; root <= r; root++) // fixed at every root
        {
            vector<TreeNode*> left = rec(l, root-1); //  Have roots of all BSTs which are present in left of "root"
            vector<TreeNode*> right = rec(root+1, r); // Have roots of all BSTs which are present in right of "root"
            
            // suppose left 4 root, and right has 3 roots, then total BSTs formed for current root is 4 X 3 = 12.
            // For each of the 4 left roots, there is 3 roots....means we have to use nested loops for connection with
            // current root.
            for (auto node_l : left){
                for (auto node_r : right){
                    
                    TreeNode *rootNode = new TreeNode(root);
                    rootNode->left = node_l;
                    rootNode->right = node_r;
                    ans.push_back(rootNode);
                }
            }
                
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> sol=rec(1,n);
        return sol;
    }
};