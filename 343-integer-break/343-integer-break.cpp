class Solution {
public:
    int recur(int n, int memo[60]){
        if(n==0){
            return 1;
        }
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
        for(int i=1;i<n;i++){
            int t=i*recur(n-i, memo);
            ans=max(ans,t);
        }
        return ans;
    }
};