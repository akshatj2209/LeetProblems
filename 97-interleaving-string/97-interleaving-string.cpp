class Solution {
public:
    bool recur(string s1, string s2, string s3, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j]!=2){
            return memo[i][j];
        }
        if(i==s1.length() && j==s2.length() && i+j==s3.length()){
            return memo[i][j]=true;
        }
        if(i+j==s3.length()){
            return memo[i][j]=false;
        }
        if(i<s1.length() && s1[i]==s3[i+j] && j<s2.length() && s2[j]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i+1,j,memo) || recur(s1,s2,s3,i,j+1,memo);
        }
        if(i<s1.length() && s1[i]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i+1,j,memo);
        }
        if(j<s2.length() && s2[j]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i,j+1,memo);
        }
        return memo[i][j]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.length()+1,vector<int>(s2.length()+1,2));
        vector<vector<bool>> dp(s1.length()+1,vector<bool>(s2.length()+1,false));
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
                    else{
                        dp[i][j]=false;
                    }
                }
                else if(j==0){
                    if(s1[i-1]==s3[i-1]){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=false;
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
                    else{
                        dp[i][j]=false;
                    }
                    
                }
            }
        }
        return dp[m][n];   
    }
};