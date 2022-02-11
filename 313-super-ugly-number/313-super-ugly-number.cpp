class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        unsigned int num=primes.size();
        unsigned int dp[n+1];
        unsigned int variate[num+1];
        memset(variate,0, sizeof(variate));
        unsigned int variation[num+1];
        for(int c=0;c<num;c++){
            variation[c]=primes[c];
        }
        int i=1;
        dp[1]=1;
        dp[0]=1;
        while(i<n){
            unsigned int ans=INT_MAX;
            for(int j=0;j<num;j++){
                ans=min(ans,variation[j]);
                
            }
            dp[i]=ans;
             for(int j=0;j<num;j++){
                if(ans==variation[j]){
                    variate[j]++;
                    variation[j]=dp[variate[j]]*primes[j];
                } 
            }
            
            i++;
            
            
        }
        return dp[n-1];
        
    }
};