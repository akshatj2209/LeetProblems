class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1)
            return 1;
        vector<int> dp(n+1);
        int i2=0;
        int i3=0;
        int i5=0;
        dp[0]=1;
        for(int i=1; i<n; i++) {    
		//Sort the ugly numbers. Since, we are multiplying with 2, 3 and 5, the resulting numbers will be guranted ugly numbers.
            int n2=dp[i2]*2;
            int n3=dp[i3]*3;
            int n5=dp[i5]*5;
            if(n2<=n3 && n2<=n5){
                i2++;
                dp[i]=n2;
            }
            if(n3<=n2 && n3<=n5){
                i3++;
                dp[i]=n3;
            }
            if(n5<=n3 && n5<=n2){
                i5++;
                dp[i]=n5;
            }
        }
        return dp[n-1];
    }
};