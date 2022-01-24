class Solution {
public:
    
    int rec(int l, int r,vector<vector<int>> &dp) 
    {
        if (l > r) return 0;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if (l == r) return dp[l][r]=1;
        
        int ans=0;
        int left=0;
        int right=0;
        for (int root = l; root <= r; root++) 
        {
            left = rec(l, root-1,dp); 
            right = rec(root+1, r,dp); 
            if(left==0){
                ans+=right;
            }
            else if(right==0){
                ans+=left;
            }
            else
            ans+=(left*right);
                
        }
        dp[l][r]=ans;
        return dp[l][r];
    }
    int numTrees(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return rec(1,n,dp);
    }
};