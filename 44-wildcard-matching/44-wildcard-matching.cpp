bool recur(string s, string p, int i, int j,vector<vector<int>> &memo){
    int c=false;
    if(memo[i][j]!=2){
        return memo[i][j];
    }
    if(i>=s.length()&&j>=p.length()){
        return true;
    }
    if(j>=p.length()){
        return false;
    }
    if(p[j]=='*' && i>=s.length()){
        c=c||recur(s,p,i,j+1,memo);
        return c;
    }
    if(i>=s.length()){
        return false;
    }
    
    if(i<s.length() &&j<p.length() &&  (s[i]==p[j] || p[j]=='?')){
        c=c||recur(s,p,i+1,j+1,memo);
    }
    if(j<p.length() && p[j]=='*'){
        c=c||recur(s,p,i,j+1,memo);
        c=c||recur(s,p,i+1,j+1,memo);
        c=c||recur(s,p,i+1,j,memo);
    }
    if(j<p.length() && p[j]!='*' && p[j]!='?' && s[i]!=p[j]){
        return false;
    }
    memo[i][j]=c;
    return memo[i][j];
}


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1,false));
        int i,j;
        if(p.length()==0 && s.length()!=0){
            return false;
        }
        dp[0][0]=true;
        bool dec=false;
        for(j=0;j<p.length();j++){
            if(p[j]!='*'){
                dec=true;
                break;
            }
        }
        if(!dec){
            return true;
        }
        for(i=1;i<=s.length();i++){
            dp[i][0]=false;
        }
        dec=true;
        for(i=1;i<=p.length();i++){
            if(p[i-1]!='*'){
                dec=false;
            }
            dp[0][i]=dec;
        }
        for(i=1;i<=s.length();i++){
            for(j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i][j] || dp[i-1][j-1];
                }
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j] || dp[i-1][j-1]|| dp[i][j-1]|| dp[i-1][j];
                }
            }
        }
        return dp[s.length()][p.length()];   
    }
};