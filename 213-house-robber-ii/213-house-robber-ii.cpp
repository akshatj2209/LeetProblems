class Solution {
public:
    int robe(vector<int>& nums, int i, int n) {
        int dp[n+2];
        if(n==1){
            return nums[0];
        }
        if(i+1==n-1){
            return nums[i+1];
        }
        dp[i]=0;
        dp[i+1]=nums[0];
        dp[i+2]=nums[1];
        for(i=3;i<=n;i++){
            dp[i]=nums[i-1] + max(dp[i-2],dp[i-3]);
        }
        return max(dp[n],dp[n-1]);
        
    }
    int rob(vector<int>& nums) {
        vector<int> arr=nums;
    long long int n=arr.size();
        if(n==1){
            return arr[0];
        }
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n-1; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        long long int nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    long long int ans=prev;
    prev = arr[1];
    prev2 =0;
    
    for(int i=2; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        long long int nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return max(prev,ans);
    }
};