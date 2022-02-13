class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        int i, j;
        for(i=2;i<=n;i++){
            for(j=1;j<i;j++){
                dp[i]=max(dp[i], max((i-j) * j,(i-j) *dp[j]));
            }
        }
        return dp[n];
    }
};