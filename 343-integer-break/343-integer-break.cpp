class Solution {
public:
    int recur(int n, int memo[60]){
        if(memo[n]!=-1){
            return memo[n];
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            int t=i*recur(n-i,memo);
            ans=max(ans,t);
        }
        return memo[n]=ans;
    }
    int integerBreak(int n) {
        int ans=1;
        int memo[60];
        memset(memo,-1,sizeof(memo));
        memo[0]=1;
        for(int i=1;i<n;i++){
            int t=i*recur(n-i, memo);
            ans=max(ans,t);
        }
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