class Solution {
public:
     int dp[5001][2]; //ith day, holding?
    int rec(vector<int>& prices,int day, bool hold){
        //base case
        if(day>=prices.size()){
            return 0;
        }
        
        if(dp[day][hold]!=-1) //in case we've already calculated the current value
            return dp[day][hold];
			
        if(hold==0){  //not holding any stock
            int opt1=rec(prices,day+1,1)-prices[day];   //we want to buy stock
            int opt2=rec(prices,day+1,0); //we dont want to buy stock
            return dp[day][hold]=max(opt1,opt2);
        }
        if(hold==1){
            int opt1=rec(prices,day+2,0)+prices[day]; //we sold the stock so hold=0 and we cant sell next day so i+2
            int opt2=rec(prices, day+1,1); //we dont want to sell
            return dp[day][hold]=max(opt1,opt2); //store the maximum in dp
        }
        
        //int fun should return someting 
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<5001;i++){ //default profit as -1 
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
		//or u can do memset(dp,-1,sizeof(dp));
		
        return rec(prices, 0, 0);
    }
};