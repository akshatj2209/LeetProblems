class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Write your code here
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
    int dp[n][m];
    int i,j;
    int c=1;
    for(i=0;i<n;i++){
        if(obstacleGrid[i][0]==1){
            obstacleGrid[i][0]=-1;
          	c=0;  
        }
        dp[i][0]=c;
        
    }
    c=1;
    for(i=0;i<m;i++){
        if(obstacleGrid[0][i]!=0 ){
            obstacleGrid[0][i]=-1;
          	c=0;  
        }
        dp[0][i]=c;
        
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(obstacleGrid[i][j]==1){
                obstacleGrid[i][j]=-1;
                dp[i][j]=0;
                continue;
            }
            int l=obstacleGrid[i-1][j];
            int u=obstacleGrid[i][j-1];
            dp[i][j]= (l+1)*dp[i-1][j]+(u+1)*dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
    }
};