class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int i,j;
        for(i=0;i<=n;i++){
            if(i==0){
                dp[i]=0;
            }
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