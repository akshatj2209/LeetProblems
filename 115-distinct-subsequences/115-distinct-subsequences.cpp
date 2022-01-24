class Solution {
public:
    int recur(string a, string b, int i, int j,vector<vector<int>> &memo){
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(j==b.length()){
            return memo[i][j]=1;
        }
        if(i==a.length()){
            return memo[i][j]=0;
        }
        if(a[i]==b[j]){
            return memo[i][j]=recur(a,b,i+1,j+1,memo)+recur(a,b,i+1,j,memo);
        }
        return memo[i][j]=recur(a,b,i+1,j,memo);
    }
    int numDistinct(string s, string t) {
        unsigned long long int dp [s.length()+1][t.length()+1];
        int m=s.length();
        int n=t.length();
        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=0;
                }
                else if (j==0){
                     dp[i][j]=1;                  
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