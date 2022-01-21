class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        
        int i;
        for(i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(j+i>n-1){
                    break;
                }
                if(dp[j+i]==-1){
                    dp[j+i]=dp[i]+1;
                }
                else{
                    dp[j+i]=min(dp[j+i],dp[i]+1);
                }
            }
        }
        return dp[n-1];
        
        
    }
};