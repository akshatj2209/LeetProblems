class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp,-1,sizeof(dp));
        unsigned int i, j, n=coins.size();
        
        dp[0]=0;
        
        for(j=0;j<n;j++){
            for(i=0;i<=amount;i++){
                if(dp[i]!=-1 && i+coins[j]<=amount){
                    if(dp[i+coins[j]]!=-1)
                    dp[i+coins[j]]=min(dp[i+coins[j]], 1+dp[i]);
                    else{
                        dp[i+coins[j]]=1+dp[i];
                    }
                }
            }
        }
        return dp[amount];
        
    }
};