class Solution {
    public:
        unordered_map < string, int > memo;
    int recur(string s) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        if (s == "" || s[0] == '0') {
            return memo[s] = 0;
        }
        if (s.length() == 1) {
            return memo[s] = 1;
        }
        if (s.length() == 2 && stoi(s.substr(0, 2)) <= 26) {
            memo[s] = 1 + recur(s.substr(1));
            return memo[s];
        }
        if (stoi(s.substr(0, 2)) <= 26) {
            memo[s] = recur(s.substr(2)) + recur(s.substr(1));
            return memo[s];
        }
        memo[s] = recur(s.substr(1));
        return memo[s];
    }
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