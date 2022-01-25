class Solution {
public:
    int profit(vector<int>& prices, int i, int j){
        int t;
        int max_ending_here=0,max_so_far=0;
        for(t=i;t<=j;t++){
            max_ending_here+=prices[t];
            if(max_ending_here>max_so_far){
                max_so_far=max_ending_here;
            }
            if(max_ending_here<0){
                max_ending_here=0;
            }
        }
        return max_so_far;
    }
    int maxProfit(vector<int>& prices) {
        int max1;
        int i, n=prices.size();
        for(i=n-1;i>0;i--){
            prices[i]-=prices[i-1];
        }
        prices[0]=0;
        int max_ending_here=0,max_so_far=0;
        int dp[n];
        for(i=n-1;i>=0;i--){
            max_ending_here-=prices[i];
            if(max_ending_here>0){
                max_ending_here=0;
            }
            if(max_ending_here<max_so_far){
                max_so_far=max_ending_here;
            }
            dp[i]=(-max_so_far);
        }
        dp[n-1]=0;
        max1=dp[0];
        
        for(i=0;i<n-1;i++){
            max_ending_here+=prices[i];
            if(max_ending_here<0){
                max_ending_here=0;
            }
            if(max_ending_here>max_so_far){
                max_so_far=max_ending_here;
            }
            max1=max(max1,max_so_far+dp[i+1]);
        }
        max1=max(max1,dp[0]);
        
        return max1;
        
    }
};