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
        return recur(n,memo);
    }
};