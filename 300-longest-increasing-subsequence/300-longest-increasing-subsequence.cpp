class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j, n=nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[j]=max(dp[j],1+dp[i]);
                }
            }
        }
        int ans=0;
        for(i=0;i<n;i++){
            cout<<dp[i]<<" ";
            ans=max(ans,dp[i]);
        }
        return ans+1;
        
    }
};