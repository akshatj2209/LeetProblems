class Solution {
public:
    int recur(int n, int memo[]){
        if(memo[n]!=-1){
            return memo[n];
        }
        if(n==0 || n==1){
            return memo[n]=n;
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans, 1+recur(n-i*i,memo));
        }
        return memo[n]=ans;
    }
    int numSquares(int n) {
        int memo[n+1];
        memset(memo,-1,sizeof(memo));
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