class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& dungeon,int row,int col)
    {
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(row>=n || col>=m)
        {
            return INT_MAX;
        }
        if(row==n-1 && col==m-1)
        {
            if(dungeon[row][col]<=0)
                return abs(dungeon[row][col])+1;
            return 1;
        }
        if(dp[row][col]!=-1)
            return dp[row][col];
        int move_down=solve(dungeon,row+1,col);
        int move_right=solve(dungeon,row,col+1);
        int min_health=min(move_down,move_right)-dungeon[row][col];
        if(min_health<=0)
            return 1;
        return dp[row][col]=min_health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return solve(dungeon,0,0);
        
    }
};