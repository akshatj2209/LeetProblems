class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n= matrix[0].size();
        int i, j;
        int dp[m+1][n+1];
        int maxi=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        return maxi*maxi;
        
    }
};