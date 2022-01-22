

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1,false));
        int i,j;
        if(p.length()==0 && s.length()!=0){
            return false;
        }
        dp[0][0]=true;
        bool dec=true;
        for(i=1;i<=s.length();i++){
            dp[i][0]=false;
        }
        for(i=1;i<=p.length();i++){
            if(p[i-1]!='*'){
                dec=false;
            }
            dp[0][i]=dec;
        }
        for(i=1;i<=s.length();i++){
            for(j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j-1]|| dp[i][j-1]|| dp[i-1][j];
                }
            }
        }
        return dp[s.length()][p.length()];   
    }
};