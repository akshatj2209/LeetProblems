class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int i,j;
        dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=1;j*j<=i;j++){
                if(dp[i]==-1){
                    dp[i]=1+dp[i-j*j];
                }
                else
                dp[i]=min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};