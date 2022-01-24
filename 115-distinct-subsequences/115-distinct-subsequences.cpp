class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned long dp [s.length()+1][t.length()+1];
        int m=s.length();
        int n=t.length();
        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0 || j==0){
                    dp[i][j]=(j==0);
                }
                else if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};