class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.length(), n = p.length();
            bool dp[m + 1][n + 1];
            memset(dp, false, sizeof(dp));
            int i, j;
            if (n == 0 && m != 0) {
                return false;
            }
            dp[0][0] = true;
            for (i = 1; i <= n; i++) {
                if (p[i - 1] != '*') {
                    break;
                }
                dp[0][i] = true;
            }
            for (i = 1; i <= m; i++) {
                for (j = 1; j <= n; j++) {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    if (p[j - 1] == '*') {
                        dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
                    }
                }
            }
            return dp[m][n];
        }
};