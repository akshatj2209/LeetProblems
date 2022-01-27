class Solution {
    public int maxProfit(int k, int[] prices) {
        if(k==0 || prices.length<2) return 0;
        int[][] dp = new int[k+1][prices.length];
        for(int i=1;i<prices.length;i++){
            for(int m=1;m<=k;m++){
                int max = 0;
                for(int j=0;j<i;j++){
                    //buy j, sell i
                    if(j==0){
                        max=Math.max(max,(prices[i]-prices[j]));
                    }
                    else 
                    max=Math.max(max,(prices[i]-prices[j])+dp[m-1][j-1]);
                }
                dp[m][i]=Math.max(max,dp[m][i-1]);         
            }
        }
        return dp[k][prices.length-1];
    }
}