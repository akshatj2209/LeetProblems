class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>>isPali(n,vector<bool>(n));
        
        for(int i = 0;i<n;i++){
            //pali for odd length
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                isPali[l][r] = true;
                l--,r++;
            }
            //pali for even length
            if(i+1<n){
                l=i,r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    isPali[l][r] = true;
                    l--,r++;
                }
            }
        }
        
        //dp: minimum number of partitions required
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i = 0;i<n;i++){
            if(dp[i]==INT_MAX)continue;
            for(int j=i;j<n;j++){
                if(isPali[i][j])dp[j+1] = min(dp[j+1],dp[i]+1);
            }
        }
        
        return dp[n]-1;

    }
};