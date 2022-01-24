class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[s1.length()+1][s2.length()+1];
        memset(dp,false,sizeof(dp));
        int m=s1.length(), n=s2.length();
        int i,j;
        if(m+n!=s3.length()){
            return false;
        }
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    if(s2[j-1]==s3[j-1]){
                        dp[i][j]=dp[i][j-1];
                    }
                }
                else if(j==0){
                    if(s1[i-1]==s3[i-1]){
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else{
                    if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]){
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                    else if(s2[j-1]==s3[i+j-1]){
                        dp[i][j]=dp[i][j-1];
                    }
                    else if(s1[i-1]==s3[i+j-1]){
                        dp[i][j]=dp[i-1][j];
                    }
                    
                }
            }
        }
        return dp[m][n];   
    }
};