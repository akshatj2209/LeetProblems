class Solution {
public:
    int uniquePaths(int m, int n) {
        int i;
        vector<int> dpr(m,1);
        vector<int> dpc(n,1);
    
        int j;
        int ans=1;
        for(i=1;i<m;i++){
       	    for(j=1;j<n;j++){
                ans=dpr[i-1]+dpc[j-1];
                dpr[i-1]=ans;
                dpc[j-1]=ans;
            }
        }
        return ans;
        
    }
};