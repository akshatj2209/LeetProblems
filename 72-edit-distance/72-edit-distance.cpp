int recur(string word1, string word2, int i, int j,vector<vector<int>> &memo){
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    
    if(i==word1.length()){
        memo[i][j]=word2.length()-j;
        return memo[i][j];
    }
    if(j==word2.length()){
        memo[i][j]=word1.length()-i;
        return memo[i][j];
    }
    
    if(word1[i]==word2[j]){
        return recur(word1,word2,i+1,j+1,memo);
    }
    memo[i][j]=1+min(recur(word1,word2,i,j+1,memo),min(recur(word1,word2,i+1,j,memo),recur(word1,word2,i+1,j+1,memo)));
    return memo[i][j];
}



class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        int m=word1.length();
        int n=word2.length();
        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i==0){
                    dp[0][j]=j;
                }
                else if(j==0){
                    dp[i][0]=i;
                }
                else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    }
                }
            }
        }
        return dp[m][n];
    }
};