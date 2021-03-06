class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.length()+1];
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<s.length();i++){
            for(int j=i;j>=0;j--){
                if(dp[j] && find(wordDict.begin(), wordDict.end(),s.substr(j,i-j+1)) != wordDict.end()){
                    dp[i+1]=  dp[j];
                    break;
                }
            }
        }
        return dp[s.length()];
        
    }
};