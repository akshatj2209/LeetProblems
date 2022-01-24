class Solution {
    public:
        int numDecodings(string s) {
            int i;
            int n=s.length();
            int dp[n+1];
            dp[n]=0;
            for(i=n;i>0;i--){
                if(s[i-1]=='0'){
                    dp[i-1]=0;
                }
                else if(i==n){
                    dp[i-1]=1;
                }
                else if(i==n-1 && stoi(s.substr(i-1, 2)) <= 26){
                    dp[i-1]=1+dp[i];
                }
                else if(stoi(s.substr(i-1, 2)) <= 26){
                    dp[i-1]=dp[i]+dp[i+1];
                }
                else{
                    dp[i-1]=dp[i];
                }
            }

            return dp[0];
        }
        
};