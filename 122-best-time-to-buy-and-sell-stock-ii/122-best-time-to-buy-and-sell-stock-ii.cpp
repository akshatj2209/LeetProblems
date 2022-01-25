class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i;
        for(i = n-1; i > 0; i --){
            prices[i]-=prices[i-1];
        }
        prices[0]=0;
        int max_so_far=0;
        int max_ending_here=0;
        for(i=0;i<n;i++){
            max_ending_here+=prices[i];
            if(prices[i]>0){
                max_so_far+=prices[i];
            }
            
        }
        return max_so_far;
        
        
    }
};